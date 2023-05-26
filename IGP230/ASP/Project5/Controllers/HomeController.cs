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

    public IActionResult Page3()
    {
        return View();
    }
    public IActionResult CarTable()
    {
        return View();
    }   
    public IActionResult FormPage()
    {
        return View();
    }

    [HttpPost]
    public IActionResult SubmitForm(string firstName, string lastName, string phone, string address, string postalCode)
    {
        TempData["FirstName"] = firstName;
        TempData["lastName"] = lastName;
        TempData["phone"] = phone;
        TempData["address"] = address;
        TempData["postalCode"] = postalCode;

        return RedirectToAction("FormSubmitted");
    }

    public IActionResult Formsubmitted()
    {
        var FirstName = TempData["FirstName"] as string;
        var lastName = TempData["LastName"] as string;
        var phone = TempData["phone"] as string;
        var address = TempData["address"] as string;
        var postalCode = TempData["postalCode"] as string;

        viewData["FirstName"] = firstName;
        viewData["LastName"] = LastName;
        viewData["phone"] = phone;
        viewData["address"] = address;
        viewData["postalCode"] = postalCode;

        return View();
    }
}
