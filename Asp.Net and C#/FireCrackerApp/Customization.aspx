<%@ Page Title="Customization" Language="C#" MasterPageFile="~/Inner.Master" AutoEventWireup="true" CodeBehind="Customization.aspx.cs" Inherits="FireCrackerApp.WebForm5" %>
<asp:Content ID="Content1" ContentPlaceHolderID="contentPlaceholderfront" runat="server">

    <!--Auto Genrated code for Grid view and data Grabs from Database -->
     <h3>Available Items :<asp:GridView ID="GridView1" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="ID" DataSourceID="Sqldata_Items" ForeColor="#333333" GridLines="None" Width="747px">
         <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
         <Columns>
             <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" ShowSelectButton="True" />
             <asp:BoundField DataField="ID" HeaderText="ID" ReadOnly="True" SortExpression="ID" />
             <asp:BoundField DataField="NAME" HeaderText="NAME" SortExpression="NAME" />
             <asp:BoundField DataField="TYPEOFF" HeaderText="TYPEOFF" SortExpression="TYPEOFF" />
             <asp:BoundField DataField="PRICE" HeaderText="PRICE" SortExpression="PRICE" />
             <asp:BoundField DataField="IMAGEOF" HeaderText="IMAGEOF" SortExpression="IMAGEOF" />
             <asp:BoundField DataField="REVIEW" HeaderText="REVIEW" SortExpression="REVIEW" />
         </Columns>
         <EditRowStyle BackColor="#999999" />
         <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
         <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
         <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
         <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
         <SelectedRowStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
         <SortedAscendingCellStyle BackColor="#E9E7E2" />
         <SortedAscendingHeaderStyle BackColor="#506C8C" />
         <SortedDescendingCellStyle BackColor="#FFFDF8" />
         <SortedDescendingHeaderStyle BackColor="#6F8DAE" />
         </asp:GridView>
         <asp:SqlDataSource ID="Sqldata_Items" runat="server" ConnectionString="<%$ ConnectionStrings:CrackerConnection %>" DeleteCommand="DELETE FROM [FireCracker] WHERE [ID] = @ID" InsertCommand="INSERT INTO [FireCracker] ([ID], [NAME], [TYPEOFF], [PRICE], [IMAGEOF], [REVIEW]) VALUES (@ID, @NAME, @TYPEOFF, @PRICE, @IMAGEOF, @REVIEW)" SelectCommand="SELECT * FROM [FireCracker]" UpdateCommand="UPDATE [FireCracker] SET [NAME] = @NAME, [TYPEOFF] = @TYPEOFF, [PRICE] = @PRICE, [IMAGEOF] = @IMAGEOF, [REVIEW] = @REVIEW WHERE [ID] = @ID">
             <DeleteParameters>
                 <asp:Parameter Name="ID" Type="Int32" />
             </DeleteParameters>
             <InsertParameters>
                 <asp:Parameter Name="ID" Type="Int32" />
                 <asp:Parameter Name="NAME" Type="String" />
                 <asp:Parameter Name="TYPEOFF" Type="String" />
                 <asp:Parameter Name="PRICE" Type="Double" />
                 <asp:Parameter Name="IMAGEOF" Type="String" />
                 <asp:Parameter Name="REVIEW" Type="String" />
             </InsertParameters>
             <UpdateParameters>
                 <asp:Parameter Name="NAME" Type="String" />
                 <asp:Parameter Name="TYPEOFF" Type="String" />
                 <asp:Parameter Name="PRICE" Type="Double" />
                 <asp:Parameter Name="IMAGEOF" Type="String" />
                 <asp:Parameter Name="REVIEW" Type="String" />
                 <asp:Parameter Name="ID" Type="Int32" />
             </UpdateParameters>
         </asp:SqlDataSource>
     </h3>   

</asp:Content>
