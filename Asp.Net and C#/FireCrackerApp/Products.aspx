<%@ Page Title="Products" Language="C#" MasterPageFile="~/Main.Master" AutoEventWireup="true" CodeBehind="Products.aspx.cs" Inherits="FireCrackerApp.WebForm2" %>
<asp:Content ID="Content1" ContentPlaceHolderID="contentPlaceholderfront" runat="server">

    <p>
    Select Type Of Cracker:<!--DropDown list Binds Unique data type from database of fircrackers -->
    <asp:DropDownList ID="DropDownList1" runat="server" DataSourceID="sds_type" DataTextField="TYPEOFF" DataValueField="TYPEOFF" AutoPostBack="True" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged">
    </asp:DropDownList><!--Connection starts -->
    <asp:SqlDataSource ID="sds_type" runat="server" ConnectionString="<%$ ConnectionStrings:CrackerConnection %>" SelectCommand="SELECT DISTINCT [TYPEOFF] FROM [FireCracker] ORDER BY [TYPEOFF]"></asp:SqlDataSource>
    <asp:Label ID="lblOutput" runat="server" Text="Label"></asp:Label><!--Output of the Cracker Table -->
</p>

</asp:Content>
