﻿using Bulky.DataAccess.Data;
using Bulky.DataAccess.Repository.IRepository;
using Bulky.Models;
using Microsoft.AspNetCore.Mvc;

namespace BulkyWeb.Areas.Admin.Controllers
{
    [Area("Admin")]
    public class CategoryController : Controller
    {
        private readonly IUnitOfWork _unitOfWork;
        public CategoryController(IUnitOfWork unitOfWork)
        {
            _unitOfWork = unitOfWork;
        }
        public IActionResult Index()
        {
            List<Category> categories = _unitOfWork.Category.GetAll().ToList();
            return View(categories);
        }

        public IActionResult Create()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Create(Category obj)
        {
            // --Custom Validations--
            /*if(obj.Name == obj.DisplayOrder.ToString())
            {
                ModelState.AddModelError("name", "Display Order and Name cannot be the same");
            }
            if(obj.Name != null && obj.Name.ToLower() == "test")
            {
                ModelState.AddModelError("", "Name cannot be 'test'");
            }*/
            if (ModelState.IsValid)
            {
                _unitOfWork.Category.Add(obj);
                _unitOfWork.Save();
                TempData["success"] = "Category created successfully";
                return RedirectToAction("Index");
            }
            return View();
        }

        public IActionResult Edit(int id)
        {
            if (id == null || id == 0)
            {
                return NotFound();
            }
            // All 3 ways in which we can retreive a record.
            Category? category = _unitOfWork.Category.Get(u => u.Id == id);
            /*Category? category1 = _db.Categories.FirstOrDefault(u => u.Id == id);*/
            /*Category? category2 = _db.Categories.Where(u => u.Id == id).FirstOrDefault();*/
            if (category == null)
            {
                return NotFound();
            }
            return View(category);
        }

        [HttpPost]
        public IActionResult Edit(Category obj)
        {
            // --Custom Validations--
            /*if(obj.Name == obj.DisplayOrder.ToString())
            {
                ModelState.AddModelError("name", "Display Order and Name cannot be the same");
            }
            if(obj.Name != null && obj.Name.ToLower() == "test")
            {
                ModelState.AddModelError("", "Name cannot be 'test'");
            }*/
            if (ModelState.IsValid)
            {

                _unitOfWork.Category.Update(obj);
                _unitOfWork.Save();
                TempData["success"] = "Category updated successfully";
                return RedirectToAction("Index");
            }
            return View();
        }

        public IActionResult Delete(int? id)
        {
            if (id == null || id == 0)
            {
                return NotFound();
            }
            // All 3 ways in which we can retreive a record.
            Category? category = _unitOfWork.Category.Get(u => u.Id == id);
            /*Category? category1 = _db.Categories.FirstOrDefault(u => u.Id == id);*/
            /*Category? category2 = _db.Categories.Where(u => u.Id == id).FirstOrDefault();*/
            if (category == null)
            {
                return NotFound();
            }
            return View(category);
        }

        [HttpPost, ActionName("Delete")]
        public IActionResult DeletePOST(int? id)
        {
            // --Custom Validations--
            /*if(obj.Name == obj.DisplayOrder.ToString())
            {
                ModelState.AddModelError("name", "Display Order and Name cannot be the same");
            }
            if(obj.Name != null && obj.Name.ToLower() == "test")
            {
                ModelState.AddModelError("", "Name cannot be 'test'");
            }*/
            Category category = _unitOfWork.Category.Get(u => u.Id == id);
            if (category == null)
            {
                return NotFound();
            }
            _unitOfWork.Category.Remove(category);
            _unitOfWork.Save();
            TempData["success"] = "Category deleted successfully";
            return RedirectToAction("Index");
        }
    }
}
