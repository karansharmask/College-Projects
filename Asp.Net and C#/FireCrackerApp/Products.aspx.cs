using System;
using System.Data;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Collections;
using System.Text;
using FireCrackerApp;


namespace FireCrackerApp
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            FillPage();
        }

        private void FillPage()
        {
            ArrayList crackerList = new ArrayList();

            if (!IsPostBack)
            {
                crackerList = Connection.GetCrackerByType("%");
            }
            else
            {
                crackerList = Connection.GetCrackerByType(DropDownList1.SelectedValue);
            }

            StringBuilder sb = new StringBuilder();

            foreach (Cracker cracker in crackerList)
            {
                sb.Append(
                    string.Format(
                        @"<table class='crackerTable'>
            <tr>
                <th rowspan='4' width='150px'><img runat='server' src='{3}' /></th>
                <th width='50px'>Name: </td>
                <td>{0}</td>
            </tr>

            <tr>
                <th>Type: </th>
                <td>{1}</td>
            </tr>

            <tr>
                <th>Price: </th>
                <td>{2} $</td>
            </tr>

           
            <tr>
                <td colspan='2'>{4}</td>
            </tr>           
            
           </table>",
                        cracker.NAME, cracker.TYPEOFF, cracker.PRICE, cracker.IMAGEOF, cracker.REVIEW));

                lblOutput.Text = sb.ToString();

            }


        }

        protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
        {
            FillPage();
        }
    }
}