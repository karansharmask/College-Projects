using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace FireCrackerApp
{
    public partial class WebForm4 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnRegister_Click(object sender, EventArgs e)
        {
            //Create a new user
            User user = new User(txtusername.Text, txtPassword.Text, txtEmail.Text);

            //Register the user and return a result message
            lblResult.Text = Connection.RegisterUser(user);
            Response.Redirect("Login.aspx");
        }
    }
}