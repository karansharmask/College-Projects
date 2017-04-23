<%@ Page Title="Registration" Language="C#" MasterPageFile="~/Main.Master" AutoEventWireup="true" CodeBehind="Register.aspx.cs" Inherits="FireCrackerApp.WebForm4" %>
<asp:Content ID="Content1" ContentPlaceHolderID="contentPlaceholderfront" runat="server">
    <table cellspacing="4" cellpadding="4">
        <tr>
            <td style="font-weight: 700">Name: </td>
            <td>
                <asp:TextBox ID="txtusername" runat="server" Width="250px"></asp:TextBox>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" 
                    ControlToValidate="txtusername" ErrorMessage="Enter user Name"></asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td style="font-weight: 700">Password: </td>
            <td>
                <asp:TextBox ID="txtPassword" runat="server" TextMode="Password" Width="250px"></asp:TextBox>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" 
                    ControlToValidate="txtPassword" ErrorMessage="Password Not Matching"></asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td style="font-weight: 700">Confirm Password: </td>
            <td>
                <asp:TextBox ID="txtConfirm" runat="server" TextMode="Password" Width="250px"></asp:TextBox>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" 
                    ControlToValidate="txtConfirm" ErrorMessage="Password not Matching"></asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td style="font-weight: 700">E-mail: </td>
            <td>
                <asp:TextBox ID="txtEmail" runat="server" Width="250px"></asp:TextBox>
                <asp:RequiredFieldValidator ID="RequiredFieldValidator4" runat="server" 
                    ControlToValidate="txtEmail" ErrorMessage="Enter E-mail"></asp:RequiredFieldValidator>
            </td>
        </tr>
        <tr>
            <td>
                <asp:Button ID="btnRegister" runat="server" Text="Register" 
                    onclick="btnRegister_Click" />
                <br />
                <asp:CompareValidator ID="CompareValidator1" runat="server" 
                    ControlToCompare="txtConfirm" ControlToValidate="txtPassword" 
                    ErrorMessage="Passwords must match"></asp:CompareValidator>
                <br />
                <asp:Label ID="lblResult" runat="server"></asp:Label>
            </td>
        </tr>
    </table>
</asp:Content>
