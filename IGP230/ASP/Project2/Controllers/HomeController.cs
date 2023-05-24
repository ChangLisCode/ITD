using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using Project2.Models;

namespace Project2.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }

        public IActionResult page1()
        {
            return View();
        }
        public IActionResult page2()
        {
            return View();
        }
    }
}