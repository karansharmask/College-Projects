// myscript1.js

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
		
			$("#movie1").append("<p class='imgformat'>" +
											 "<img src='_images/" +
											 $(xml).find("moviePoster:nth(0)").text() +
											 "' width='100'>" + 
											"</p>"
											);		
			
			$("h2").css("text-align", "center").css("font-weight", "bold");
			
			$("h2").append("MovieName: " + $(xml).find("movie:nth(0)").attr("movieName") +	// +1
												"<br><br>"); 
			$(xml).find("movie:nth(0)").each(function() {
				$("h2").append("Movie Director: <span style='text-decoration:underline;'>" +
													$(xml).find("movieDirector:nth(0)").text() + 
													"</span><br><br>");
				$("h2").append("Movie Type:" +  $(xml).find("movieType:nth(0)").text() + 
													"<br><br>");	
				
			});						
	}  
	
	
	
	
	
	
	
	
	
	
