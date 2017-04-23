

// myscript.js

/*
        Name: karan sharma
		 Id: 991 377 695
		 Assignment: 01
	     Date: 1st June, 2016
	                            */
	$(document).ready(function(){	
		$.ajax({
			type: "GET",
			url: "a1.xml",
			dataType: "xml",
			success: handleResponse
		});		
		
	}); // end of doc ready 
	
	
	function handleResponse(xml) {
		console.log("in hr");
		var n=0;
		
		
		$("#e0").append("<img class='photo' src='_images/" + $(xml).find("image").text() + "' width='75%' height='75%'/>" + "<br>");
		
		$("#e1").css("text-align", "center").css("font-weight", "bold");
		$("#e1").append(
						"<p class='content'>" +
						 "NAME: " + 
						$(xml).find("studentName").text() +
						"<br>" +
						 "Student ID: " + 
						$(xml).find("student:nth(0)").attr("studentNumber") +
						"<br>" +
						"Student Program: " + 
						$(xml).find("studentProg").text() + 
						"<br>" +	
						 "Student Campus: "  +
						$(xml).find("studentCampus").text() + 
						"</p>"
						);

		
		
		
		$(xml).find("movie").each(function() {
						// Create a link to individual page <a> tag
						$("#b"+n).append(
								"<a href='" + 
								$(this).find("id").text() +
								".html'>" + 
							 "<p class='imgformat'>" + 
							 "<img src='_images/" +
							 $(this).find("moviePoster").text() + 
							 "' width ='85',height='80'>" + 
							  "</p>"
								
								);							
												
			n++;
		});
	}
	
	
	
	
	
	
	
	
	
	
