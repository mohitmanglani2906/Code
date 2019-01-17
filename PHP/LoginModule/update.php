<?php
	session_start();
	$servername="localhost";
	$username="root";
	$password="";
	$dbName="studentdetails";

	try{
		$conn=mysqli_connect($servername,$username,$password,$dbName);
		
	}
	catch(MySQLi_Sql_Exception $ex)
	{
		echo $ex;
	}
	$umob = $_SESSION['mob'];
	
	if($umob == "")
	{
		header("location:index.php");
	}

	$sql = "SELECT `fname`,`lname`,`email`,`mobile`,`branch`,`semester`,`password`,`pic` FROM `stu_info` WHERE mobile='$umob'";

		$rec1=mysqli_query($conn,$sql);
		$row=mysqli_fetch_array($rec1);
		
		 // echo $row['fname'];	
		 // echo $row['pic'];

	if(isset($_POST['update']))
	{
		$first_name= $_POST['fname'];
		$last_name = $_POST['lname'];
		$email_id =$_POST['email'];
		$mobile_no= $_POST['number'];
		$branch = $_POST['branch'];
		$semester=$_POST['semester'];
		$password=$_POST['pwd'];
		$repassword=$_POST['repwd'];
		//$pic = $row['pic'];
		if(empty($first_name))
		{
			$first_name=$row['fname'];	
		}
		if(empty($last_name))
		{
			$last_name=$row['lname'];
		}
		if(empty($email_id))
		{
			$email_id=$row['email'];
		}
		if( filter_var($email_id, FILTER_VALIDATE_EMAIL) == "")
		{
			echo '<script>';
				echo 'alert("Wrong Email address!!")';
			echo '</script>';
		}
		if(empty($mobile))
		{
			$mobile_no=$row['mobile'];
		}
		if( strlen($mobile_no) != 10 || !ctype_digit($mobile_no	)){
 			
			echo '<script>';
				echo 'alert("Phone must be of 10 digits!!")';
			echo '</script>';
 		}
		if(empty($branch))
		{
			$branch=$row['branch'];
		}
		if(empty($semester))
		{
			$semester=$row['semester'];
		}
		if(empty($password))
		{
			$password=$row['password'];
		}
		
		if($password!=$repassword)
		{
				echo '<script>';
					echo 'alert("Password and Repassword should be same")';
				echo '</script>';

		}



		$target_dir = "uploads/";
		$target_file = $target_dir . rand() . "_" . basename($_FILES["fileToupload"]["name"]);
		$uploadok = 1;

		if(empty(basename($_FILES["fileToupload"]["name"])))
		{
			$target_file=$row['pic'];
			$pic2=$target_file;
			echo  "<br>" . $target_file;
			$uploadok=1;
			 if (move_uploaded_file($_FILES["fileToupload"]["tmp_name"], $target_file))
		    {
		        $pic2 = $target_file; 
		    } 
		   
		}
		else
		{
			$imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));
			$check = getimagesize($_FILES["fileToupload"]["tmp_name"]);
			if(empty($check))
			{
				echo '<script>';
					echo 'alert("Choose an image!!")';
				echo '</script>';
			}
			if($check!==false)
			{
				$uploadok=1;
			}
			else
			{
				$uploadok=0;
				echo '<script>';
					echo 'alert("File is not a Image!!")';
				echo '</script>';
			}
			if(file_exists($target_file))
			{
				echo '<script>';
					echo 'alert("File already exits!!!")';
				echo '</script>';
				$uploadOk = 0;
			}
			if($_FILES["fileToupload"]["size"]>500000)
			{
				echo '<script>';
					echo 'alert("File is too large!!")';
				echo '</script>';
				 $uploadOk = 0;
			}
			
			if($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
					&& $imageFileType != "gif" )
			{ 
				echo '<script>';
					echo 'alert("File type should be jpg png or jpeg")';
				echo '</script>';
	  		    $uploadOk = 0;
			}
			if($uploadok==1)
			{
					if (move_uploaded_file($_FILES["fileToupload"]["tmp_name"], $target_file))
				    {
				        $pic2 = $target_file; 
				    } 
			}

			else
			{
	   			   echo '<script>';
						echo 'alert("Soooooorry file cant be uploaded ")';
					echo '</script>';
	   			 exit;
			} 
	
		}

		
		

		$sql1="UPDATE `stu_info` SET `fname`='$first_name',`lname`='$last_name',`email`='$email_id',`mobile`='$mobile_no',`branch`='$branch',`semester`='$semester',`password`='$password',`pic`='$pic2' WHERE mobile='$umob'"; 
		$res=mysqli_query($conn,$sql1);

	}	
?>


<!DOCTYPE html>
<html>
<head>
	<title>Update Your Info.....</title>
	<link rel="stylesheet" type="text/css" href="update.css">
</head>
<body>
	<div class="contact1">
		<h1 class="h1contact" style="float: left;">Update!!</h1>
		<h1 style="float:right;" id="home"><a href="loggedin.php" >Go Back!!</a></h1>
				<form class="form1" action="" style="margin-top: 30px;" method="post" enctype="multipart/form-data">
					<td><input type="text" name="fname" placeholder="First Name:" class="contactform" value=""></td>
					<input type="text" name="lname" placeholder="Last Name:" value=""  class="contactform">
					<input type="Email" name="email" placeholder="Email:" value=""  class="contactform" style="margin-top: 10px; ">
					<input type="text" name="number" placeholder="Phono no:" value=""  class="contactform" value="" style="margin-top: 10px;">
					
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
					<input type="password" placeholder="Password" name="pwd" value=""   class="contactform" style="margin-top: 10px;">
					<input type="password" placeholder="Confirm Password" name="repwd" value=""   class="contactform" style="margin-top: 10px;">
					
					<input type="file" name="fileToupload" id="fileToupload"  class="contactform">
					<input type="submit" name="update" placeholder="" value="UPDATE" placeholder="contactform" id="btn1" style="width:100px;">
					<!-- <input type="submit" name="back" placeholder="" value="GO TO HOME" placeholder="contactform" id="btn1" style="width:auto"> -->

					<?php
						if(isset($_POST['back']))
						{
							header("location: loggedin.php");
						}
					?>
				</form>	
	</div>
</body>
</html>