using Bulky.DataAccess.Repository.IRepository;
using Bulky.Models;
using Bulky.Models.ViewModels;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;

namespace BulkyWeb.Areas.Admin.Controllers
{
    [Area("Admin")]
    public class ProductController : Controller
    {
        private readonly IUnitOfWork _unitOfWork;
        private readonly IWebHostEnvironment _webHostEnvironment; // To retreive wwwroot path
        public ProductController(IUnitOfWork unitOfWork, IWebHostEnvironment webHost)
        {
            _unitOfWork = unitOfWork;
            _webHostEnvironment = webHost;
        }
        public IActionResult Index()
        {
            List<Product> obj = _unitOfWork.Product.GetAll(includeProperties: "Category").ToList();
            return View(obj);
        }

        public IActionResult Upsert(int? id)
        {
            /*IEnumerable<SelectListItem> Categories = _unitOfWork.Category.GetAll().Select(u => new SelectListItem
            {
                Text = u.Name,
                Value = u.Id.ToString()
            });

            *//*ViewData["CategoryList"] = Categories; -- If we use ViewData *//*
            ViewBag.CategoryList = Categories;*/
            ProductVM product = new ProductVM
            {
                CategoryList = _unitOfWork.Category.GetAll().Select(u => new SelectListItem
                {
                    Text = u.Name,
                    Value = u.Id.ToString()
                }),
                Product = new Product()
            };
            if(id == null || id == 0)
            {
                //Create
                return View(product);
            } else
            {
                //Update
                product.Product = _unitOfWork.Product.Get(u => u.Id == id);
                return View(product);
            }
        }

        [HttpPost]
        public IActionResult Upsert(ProductVM obj, IFormFile? file)
        {
            if (ModelState.IsValid)
            {
                string wwwRootPath = _webHostEnvironment.WebRootPath;
                if(file != null)
                {
                    string fileName = Guid.NewGuid().ToString() + Path.GetExtension(file.FileName); // Generate a new name for the file
                    string productPath = Path.Combine(wwwRootPath, @"images\product"); // Path to product folder inside wwwroot

                    //In case of update if the product already has an image file and the user wants to change that file
                    if (!string.IsNullOrEmpty(obj.Product.ImageURL))
                    {
                        //delete the old image
                        var oldImagePath =
                            Path.Combine(wwwRootPath, obj.Product.ImageURL.TrimStart('\\'));

                        if (System.IO.File.Exists(oldImagePath))
                        {
                            System.IO.File.Delete(oldImagePath);
                        }
                    }

                    using (var filestream = new FileStream(Path.Combine(productPath, fileName), FileMode.Create))
                    {
                        file.CopyTo(filestream);
                    }
                    obj.Product.ImageURL = @"\images\product\" + fileName;
                }
                if (obj.Product.Id == 0)
                {
                    //If we don't have productId in obj then it's add
                    _unitOfWork.Product.Add(obj.Product);
                }
                else
                {
                    //else it's update
                    _unitOfWork.Product.Update(obj.Product);
                }
                _unitOfWork.Save();
                TempData["success"] = "Product created successfully";
                return RedirectToAction("Index");
            }
            return View();
        }

        #region API Calls

        [HttpGet]
        public IActionResult GetAll()
        {
            List<Product> obj = _unitOfWork.Product.GetAll(includeProperties: "Category").ToList();
            return Json(new {data = obj});
        }

        [HttpDelete]
        public IActionResult Delete(int? id)
        {
            var productToBeDeleted = _unitOfWork.Product.Get(u => u.Id == id);
            if (productToBeDeleted == null)
            {
                return Json(new { success = false, message = "Error while deleting" });
            }

            var oldImagePath =
                           Path.Combine(_webHostEnvironment.WebRootPath,
                           productToBeDeleted.ImageURL.TrimStart('\\'));

            if (System.IO.File.Exists(oldImagePath))
            {
                System.IO.File.Delete(oldImagePath);
            }

            _unitOfWork.Product.Remove(productToBeDeleted);
            _unitOfWork.Save();

            return Json(new { success = true, message = "Delete Successful" });
        }

        #endregion

    }
}
