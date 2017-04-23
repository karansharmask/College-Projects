using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace FireCrackerApp
{
    public partial class Inner : System.Web.UI.MasterPage
    {
        protected void Page_Load(object sender, EventArgs e)
        {

            if (!IsPostBack) //code for Image to come Instant after load the page
            {
                SetImageURl();
            }
            //Check if a user is logged in with the hep of session
            if (Session["login"] != null)
            {
                lblLogin.Text = "Welcome " + Session["login"];
                lblLogin.Visible = true;
                LinkButton1.Text = "Logout";
            }
            else
            {
                lblLogin.Visible = false;
                LinkButton1.Text = "Login";
            }
        }

        protected void LinkButton1_Click(object sender, EventArgs e)
        {

            //User logs in 
            if (LinkButton1.Text == "Login")
            {
                Response.Redirect("Login.aspx");
            }
            else
            {
                //User logs out
                Session.Clear();
                Response.Redirect("Home.aspx");
            }
        }
        protected void Slide_Click(object sender, EventArgs e) //Extract method of random Image
        {
            SetImageURl();

        }

        private void SetImageURl() //Random Image come everytime 
        {
            Random _rand = new Random();
            int i = _rand.Next(1, 6);
            SlideShow.ImageUrl = "~/Image/Banner/" + i.ToString() + ".jpg";
        }
    }
}