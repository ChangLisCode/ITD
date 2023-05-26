using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using Project3.Models;

namespace Project3.Controllers;

public class HomeController : Controller
{

    public IActionResult Index()
    {
        return View();
    }

    public IActionResult Page1()
    {
        return View();
    }
    public IActionResult Page2()
    {
        return View();
    }   
    public IActionResult Page3()
    {
        return View();
    }

}
