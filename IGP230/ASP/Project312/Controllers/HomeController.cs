using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using Project3.Models;

namespace WorkBC.Controllers;

public class HomeController : Controller
{

    public IActionResult Index()
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
    public IActionResult Page4()
    {
        return View();
    }
}
