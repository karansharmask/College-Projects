// myscript.js

/*
        Name: karan sharma
		 Id: 991 377 695
		 Assignment: 02
	     Date: 15th June, 2016
	                            */

var rowID;					
var xmlData;				
var menuClick=true;		
$(document).on("pagecreate","#home",function(e,data){ 
		console.log("page created");
    $.ajax({
        type: "POST",
        url: "a2.xml",
        dataType: "xml",
        success: function(xml)
		 {
			 buildmenu(xml)
		 },
				error: function(e) 
				{
					alert(e.status + "-" + e.statusText);
				}
		
    });
});

function buildmenu(xml)
{
	var n=0;
	xmlData=xml;
		$("ul#BookMenu").html("");

	console.log("in function");
				$("h1").html($(xml).find("BookSite").text());
				
				
				
  $("h2").html(
  "<p>Name:" +       $(xml).find("StudentName").text() +
  
   "<br>"   + 
  "ID:" +
									$(xml).find("StudentName").attr("studentNumber") +
						                  "<br>" +    
						                           "prog:" + 
						$(xml).find("StudentName").attr("studentProg") +
											 "</p>");
											 
											 

	$(xml).find("Book").each(function() {
		$("ul#BookMenu").append("<li li-id='"+ n + "'>" + 
																"<a href='#Singlepage'>" + 
																	$(this).find("Name").text() + 
																"</a></li>");
		$(".Book"+n).html($(this).find("Name").text());		
		n++;
	});
	$("ul#BookMenu").listview("refresh");		//Must be done!!!!

}
// selection from menu
$(document).on("click", "#BookMenu >li", function() {
	rowID = $(this).closest("li").attr("li-id");
});

$(document).on("pageshow","#Singlepage",function(){  

			parseXML(xmlData, rowID);
});
// selection from navigation bar
$(document).on("click", ".Book0", function() { rowID=0; menuClick=false; parseXML(xmlData,rowID);});	
$(document).on("click", ".Book1", function() { rowID=1; menuClick=false; parseXML(xmlData,rowID);});
$(document).on("click", ".Book2", function() { rowID=2; menuClick=false; parseXML(xmlData,rowID);});
$(document).on("click", ".Book3", function() { rowID=3; menuClick=false; parseXML(xmlData,rowID);});


		

function parseXML(xml, rowID){
	console.log(rowID);						//used for debug - comment out when working
    $('#Book-data').html("");
		$("#Book-data").html(
		
		"<img src='_images/" + 
							$(xml).find('Book:nth(' + rowID + ")").find("Name").attr("Image")+ "' width='100' />" +
		            "<center><h3>" +  
							$(xml).find("Name:nth(" + rowID + ")").text() + "</h3>"	+
					"<h4>Author: " + 
							$(xml).find('AuthorName:nth(' + rowID + ")").text() + "</h4>" +
					"<h4>Publisher: " + 
							$(xml).find('PublisherName:nth(' + rowID + ")").text() + "</h4>" +
					"<h4>Book-Type: " + 
							$(xml).find('Book:nth(' + rowID + ")").find("Desc").attr("BookType") + "</h4>" +
					"<h4>Current Price: " + 
							$(xml).find('CurrentPrice:nth(' + rowID + ")").text() + "</h4>" +
					"<p><b>Description: </b><br>" + 
							$(xml).find('Desc:nth(' + rowID + ")").text() + "</p><center>"
												);			
}
$(document).on("pagecreate","#Singlepage",function()
{
	console.log("page created");
		$.ajax({
        type: "POST",
        url: "a2.xml",
        dataType: "xml",
        success: function (xml) {
						parseXML(xml, rowID)},			// to send multiple parameters
        error: function (request,error) {
            alert('Network error has occurred: ' + error);}
		 });
		if (menuClick) {
			parseXML(xmlData, rowID);
		}
		menuClick=true;
});