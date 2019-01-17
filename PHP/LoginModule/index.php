<?php
	session_start();
	$conn=mysqli_connect("localhost","root","","studentdetails");
	//mysqli_select_db("studentdetails");
	if(isset($_REQUEST['submitlogin']))
{
	$mob=$_REQUEST['mobile'];
	$pwd=$_REQUEST['password'];
	
	$sel="SELECT * FROM `stu_info` WHERE mobile='$mob' and password='$pwd'";
	$ex=mysqli_query($conn,$sel);
	$fet=mysqli_fetch_array($ex);
	$no=mysqli_num_rows($ex);
	echo $no; 
	if($no==1)
	{
		$_SESSION['mob']=$fet[3];
		$_SESSION['pwd']=$fet[6];
		
		
	
		echo"<script>
			alert('login successfully')
			window.location='loggedin.php';
		</script>";
	}
	else
	{
		echo"<script>
			alert('Incorrect username or password')
			window.location='index.php';
		</script>";
	}
}
?>
<!DOCTYPE html>
<html>
<head>
	<title>Welcome</title>
	 <link rel="stylesheet" type="text/css" href="index.css">
</head>
<body>
	<h1 align="center" class="h1contact">Welcome to Mohit's Blog!!!!!!</h1>
	
	
	<div class="login">
		<form action="" method="get" >
			<h1 class="h1contact">Log In</h1>
			<input type="text" name="mobile"  placeholder="Phone" required="true" class="logininput" >
			<input type="password" name="password" placeholder="Password" required="true" class="logininput">
			<input type="submit" name="submitlogin" id="btnlogin">
		</form>
	</div>

	<div class="contact" id="contact1">
		<hr style="width: 80%;margin-top:400px;margin-left: 120px;opacity: .2;">
		<div class="contact1">
			<h1 class="h1contact">Sign Up!!</h1>
			<!-- <p id="p1contact">We offer full-service catering for any event, large or small. We understand your needs and we will cater the food to satisfy the biggerst criteria of them all, both look and taste. Do not hesitate to contact us.</p>
			<p id="p2contact">Catering Service, 42nd Living St, 43043 New York, NY</p>
			<p style="margin-top: 20px;">You can also contact us by phone 00553123-2323 or email catering@catering.com, or you can send us a message here:</p> -->

				<form class="form1" action="sucess.php" style="margin-top: 30px;" method="post" enctype="multipart/form-data">
					<input type="text" name="fname" placeholder="First Name" required="true" class="contactform" >
					<input type="text" name="lname" placeholder="Last Name" required="true" class="contactform">
					<input type="Email" name="email" placeholder="Email" required="true" class="contactform" style="margin-top: 10px; ">
					<input type="text" name="number" placeholder="Mobile no" required="true" class="contactform" value="" style="margin-top: 10px;">
					
					<select name="branch" style="width:500px;margin-top: 10px;border:none;height:40px;border-bottom: 1px solid black; font:inherit;font:inherit;padding: 10px;">
						<option value="">Branch</option>
						<option value="IT">Information & Technology</option>
						<option value="com">Computer</option>
						<option value="mech">Mechanical</option>
						<option value="ec">Electronics</option>
						<option value="nano">Nano</option>
						<option value="ee">Electrical</option>
					</select>
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
					<select name="semester" class="input1" style="width:500px;border:none;height:40px;border-bottom: 1px solid black;font: inherit;padding: 10px;">
						<option value="">Semester</option>
						<option value="1">1</option>
						<option value="2">2</option>
						<option value="3">3</option>
						<option value="4">4</option>
						<option value="5">5</option>
						<option value="6">6</option>
					</select>
					<input type="password" name="pwd" placeholder="Password" required="true"  class="contactform" style="margin-top: 10px;">
					<input type="password" name="repwd" placeholder="Confirm Password" required="true"  class="contactform" style="margin-top: 10px;">
					
					<input type="file" name="fileToupload" id="fileToupload" required="true" class="contactform">
					<input type="submit" name="submit" placeholder="" value="SUBMIT" placeholder="contactform" id="btn1" style="width:100px;">
				</form>	
		</div>
	</div>







	<!-- <form method="post" align="center" class="form1">
		First Name:&nbsp;&nbsp;<input type="text" name="fname" required="true" id="fname" placeholder="Enter First Name :" class="input1"><br>
		Last Name:<input type="text" name="lname" required="true" id="lname" placeholder="Enter Last Name :" class="input1"><br>
		Email id:&nbsp;&nbsp;&nbsp;<input type="Email" name="email" required="true" id="email" placeholder="Enter your Mail id :" class="input1"><br>
		Mobile no:<input type="text" name="number" required="true" id="number" placeholder="Enter your Phone Number :" class="input1"><br>
		Semester:<select class="input1" style="width:310px;">
			<option></option>
			<option>1</option>
			<option>2</option>
			<option>3</option>
			<option>4</option>
			<option>5</option>
			<option>6</option>
		</select><br>
		Branch:&nbsp;&nbsp;&nbsp;<select class="input1" style="width:310px;">
			<option></option>
			<option>Information & Technology</option>
			<option>Computer</option>
			<option>Mechanical</option>
			<option>Electronics</option>
			<option>Nano</option>
			<option>Electrical</option>
		</select>

	</form> -->
</body>
</html>