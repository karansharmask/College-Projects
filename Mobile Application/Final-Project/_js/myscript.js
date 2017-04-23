var dataObject;
var geocoder,info, labelIndex =0;;
var labels = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
$(document).ready(function (){
	
	if (navigator.geolocation) {
			info = new google.maps.InfoWindow({
			content: "Where am I?",
			maxWidth: 150		
			});
			geocoder = new google.maps.Geocoder();
	} else {
		alert("Geolocation is not supported by this browser.");
	}

	
	
    $.ajax({
        type: "GET",
        url: "myJson.json",
        dataType: "json",
        success:function(data) 
		{
		
			dataObject=data;
			for (var i=0; i < data.products.length; i++)  {
			$("#info").append(
									"<li>" +
									"<span onclick='createProd("+i+")'>"  +
									"<img style='height:100px;' src='" +data.products[i].prodImg+"'"+" />"+
									data.products[i].prodName +
									"</span></li>"
									);
			}$("#info").append("<ul>");
			
			
			
			
			
			$("#customerMain").click(function(){
			
			$("#info").html("");
			for (var i=0; i < data.customer.length; i++)  {
			$("#info").append(
									"<li>" +
									"<span onclick='createCust("+i+")'>" +
									data.customer[i].compName +
									"</span></li>"
									);
			}$("#info").append("<ul>");
			});
			
			
			$("#productMain").click(function(){
			
			$("#info").html("");
			for (var i=0; i < data.products.length; i++)  {
			$("#info").append(
									"<li>" +
									"<span onclick='createProd("+i+")'>" +
									"<img style='height:100px;' src='" +data.products[i].prodImg+"'"+" />"+
									data.products[i].prodName +
									"</span></li>"
									);
		
			}$("#info").append("<ul>");
			});
			
			
			$("#invoiceMain").click(function(){
			
			$("#info").html("");
			for (var i=0; i < data.invoice.length; i++)  {
			$("#info").append("<li>" +
							       "<span  onclick='createInv("+i+")'>" +
									data.invoice[i].invNum +
									"</span></li>"
									);
		
			}$("#info").append("<ul>");
			
			
			});
		}
	});
	
	
	
	
	
	
	
		
	
	
	
	
	
	
	
});

function mail(i)
{
	location.href = "mailto:"+dataObject.customer[i].compEmail;
	
}

function homeBtnClick(){
	location.href="#home";
	location.reload();
}

function drawMap(i){
	var address=dataObject.customer[i].compAddr;
	geocoder.geocode( { 'address': address}, function(results, status) {
        if (status == google.maps.GeocoderStatus.OK) {
	    var lat = results[0].geometry.location.lat();
	    var lng = results[0].geometry.location.lng();
		
		var latlng = new google.maps.LatLng(lat,lng); 
		
		var mapOptions = {
                        center: latlng,
                        zoom: 15,
                        //ROADMAP, HYBRID, SATELLITE, TERRAIN
                        mapTypeId: google.maps.MapTypeId.ROADMAP
                        };
						
                    
                    //  Display map
                    var map = new google.maps.Map($("#map-canvas")[0], mapOptions);
					myLoc = new google.maps.Marker ({
						map: map,
						animation: google.maps.Animation.DROP,
						position: latlng,
						label: labels[labelIndex++ % labels.length]			
					   });
					   
									 
			 
       }
	});
	
	
	
}

function createCust(i)
{
	location.href="#customerDetails";
			
	       $("#indiCustomer").html("Company ID :"+dataObject.customer[i].compId+"<br>"+
			"Company Name :"+dataObject.customer[i].compName+"<br>"+
			"Address :<span  onclick='drawMap("+i+")' >"+dataObject.customer[i].compAddr+"</span><br>"+
			"Company Contact :"+dataObject.customer[i].compContact+"<br>"+
			"Company Phone# :"+dataObject.customer[i].compPontact+"<br>"+
			"Company Email:<span  onclick='mail("+i+")'>"+dataObject.customer[i].compEmail+"</span><br>");
			$("#indiCustomer").append("<ul>");
			for(var j=0;j<dataObject.customer[i].invNum.length;j++){
				$("#indiCustomer").append("Invoice Num :"+"<li>"+dataObject.customer[i].invNum[j].Invoice+"</li> <br>");
			}
			$("#indiCustomer").append("<ul>");
}


function createProd(i)
{
	location.href="#productpage";

	//$("#indiProduct").append(dataObject.products[i].compId+"<br>");
				$("#img").html("<img style='height:130px;' src='"+dataObject.products[i].prodImg+"' border='2'>");
				$("#indiProduct").html(
				"<span>Product ID :</span>"+dataObject.products[i].prodId+"<br>"+
				"<span>Product :</span>"+dataObject.products[i].prodName+"<br>"+
				"<span>Description :</span>"+dataObject.products[i].prodDesc+"<br>"+
				"<span>Amount :</span>"+dataObject.products[i].prodAmt+"<br>");
}


function createInv(i)
{
	location.href="#invoicepage";

	        $("#prinv").html("<span>Invoice Number :</span>"+dataObject.invoice[i].invNum+"<br>"+
			"<span>Invoice Date :</span>"+dataObject.invoice[i].invDate+"<br>"+
			"<span>Invoice Amount :</span>"+dataObject.invoice[i].invAmt+"<br>"+
			"<span>Company ID :</span>"+dataObject.invoice[i].compId+"<br>");
}



