<%@ Page Title="Login" Language="C#" MasterPageFile="~/Main.Master" AutoEventWireup="true" CodeBehind="Login.aspx.cs" Inherits="FireCrackerApp.WebForm3" %>
<asp:Content ID="Content1" ContentPlaceHolderID="contentPlaceholderfront" runat="server">
     <table>
        <tr>
            <td><b>Login: </b></td>
            <td>
                <asp:TextBox ID="txtLogin" runat="server"></asp:TextBox>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" 
                    ErrorMessage="Incorrect Login" ControlToValidate="txtLogin"></asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td><b>Password: </b></td>
            <td>
                <asp:TextBox ID="txtPassword" runat="server" TextMode="Password"></asp:TextBox>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" 
                    ErrorMessage="Enter Proper Password" ControlToValidate="txtPassword"></asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td>
                <asp:Button ID="btnLogin" runat="server" Text="Login" 
                    onclick="btnLogin_Click" /><br/>
                <asp:Label ID="lblError" runat="server" Text=""></asp:Label>
                <br />
                <asp:LinkButton ID="LinkButton2" runat="server" 
                    PostBackUrl="Register.aspx" CausesValidation="False">Register</asp:LinkButton>
            </td>
        </tr>
    </table>
</asp:Content>
