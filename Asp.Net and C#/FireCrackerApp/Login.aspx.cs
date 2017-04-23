using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace FireCrackerApp
{
    public partial class WebForm3 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnLogin_Click(object sender, EventArgs e)
        {

            User user = Connection.LoginUser(txtLogin.Text, txtPassword.Text);

            if (user != null)
            {
                //Store login variables in session
                Session["login"] = user.UserName;

                Response.Redirect("Customization.aspx");
            }
            else
            {
                lblError.Text = "Login failed";
            }

        }
    }
}