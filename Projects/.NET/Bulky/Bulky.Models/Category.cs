using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace Bulky.Models
{
    public class Category
    {
        [Key]
        public int Id { get; set; }
        [Required(ErrorMessage = "Category Name is required")]
        [DisplayName("Category Name")]
        [MaxLength(30)]
        public string Name { get; set; }
        [DisplayName("Display Order")]
        [Required(ErrorMessage = "Display Order cannot be empty")]
        [Range(1, 100, ErrorMessage = "Display Order must be between 1 to 100")]
        public int DisplayOrder { get; set; }
    }
}
