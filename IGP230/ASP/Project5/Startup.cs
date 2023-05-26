using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;

namespace Project2
{
    public class Startup
    {
        public IConfiguration Configuration{ get; }
        public Startup(IConfiguration configuration)
        {
            Configuration = configuration;
        }
        public void ConfigureServices(IServiceCollection services)
        {
            services.AddControllersWithViews();
        }
        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
            if (env.IsDevelopment())
            {
                if (env.IsDevelopment())
                {
                    app.UseDeveloperExceptionPage();
                }
                else
                {
                    app.UseExceptionHandler("/Home/Error");
                    app.UseHsts();
                }
                app.UseHttpsRedirection();

                app.UseStaticFiles();

                app.UseRouting();

                app.UseEndpoints(endpoints =>
                {
                    endpoints.MapControllerRoute(                        
                        name: "default",
                        pattern: "{controller = Home}/{action = Index}/{id?}");

                    endpoints.MapControllerRoute(
                        name: "Page3",
                        pattern: "Home/Page3",
                        defaults: new { controller = "Home", action = "Page3"});

                    endpoints.MapControllerRoute(
                        name: "carTable",
                        pattern: "Home/CarTable",
                        defaults: new { controller = "Home", action = "CarTable"});

                    endpoints.MapControllerRoute(
                        name: "FormSubmitted",
                        pattern: "Home/FormSubmitted",
                        defaults: new { controller = "Home", action = "FormSubmitted"});

                });
            }
        }
    }
}
    


