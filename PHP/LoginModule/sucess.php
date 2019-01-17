
<?php
	$serverename = "localhost";
	$username="root";
	$password="";
	$dbName="studentdetails";

	try{
		$conn=mysqli_connect($serverename,$username,$password,$dbName);
		//echo "Connected";
		// echo "<script type='text/javascript'>";
		// echo 	"alert('Connected')";
		// echo "</script>";

	}
	catch(MySQLi_Sql_Exception $ex)
	{
		echo("Error in Connection");
	}
		if(empty($_POST)) // if someone fills empty details
		{
			header("location: index.php");
			exit;
		}

		$fname=$_POST["fname"];
		$lname=$_POST["lname"];
		$email=$_POST["email"];
		$number=$_POST["number"];
		$branch=$_POST["branch"];
		$semester=$_POST["semester"];
		$password=$_POST["pwd"];
		$repassword=$_POST["repwd"];

		// For file operations

		$target_dir = "uploads/";
		$target_file = $target_dir . rand() . "_" . basename($_FILES["fileToupload"]["name"]);
		$uploadOk = 1;
		$imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));
		$errors = [] ;
		$check = getimagesize($_FILES["fileToupload"]["tmp_name"]); //fileToupload

		if(isset($_POST["submit"]))
		{
			$check = getimagesize($_FILES["fileToupload"]["tmp_name"]);
		    if($check !== false) {
		        //echo "File is an image - " . $check["mime"] . ".";
		        $uploadOk = 1;
		    } else {
		        echo "File is not an image.";
		        $uploadOk = 0;
		    }
		}
		
		if(file_exists($target_file))
		{
			$errors[] = "File already exits :";
			echo "File already exits :";
			$uploadOk = 0;
		}
		if($_FILES["fileToupload"]["size"]>500000)
		{
			$errors[] = "Sorry, File is too large";
			echo "Sorry, File is too large";
			 $uploadOk = 0;
		}
		if($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
				&& $imageFileType != "gif" )
		{
  		  $errors[]= "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
  		  echo  "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
  		   $uploadOk = 0;
    
		}

		

		if(empty($fname))
		{
			$errors[] = "First Name was empty :";
		}
		if(empty($lname))
		{
			$errors[] = "Last Name was empty :";
		}
		if(empty($email))
		{
			$errors[] = "Email was empty :";
		}
		if( filter_var($email, FILTER_VALIDATE_EMAIL) == "")
		{
			$errors[] = "Wrong email address :";
		}
		if(empty($number))
		{
			$errors[] = "Number was empty :";
 		}

 		if( strlen($number) != 10 || !ctype_digit($number)){
 			$errors[] = "Phone must be 10 digit :";
 		}
 		if(empty($branch))
 		{
 			$errors[] = "Branch was empty :";
 		}
 		if(empty($semester))
 		{
 			$errors[] = "semester was empty :";

 		}
 		if(empty($password))
 		{
 			$errors[] = "Password was empty :";
 		}
 		if(empty($repassword))
 		{
 			$errors[] = "repassword was empty :";
 		}
 		if($password != $repassword)
 		{
 			$errors[] = "Password mismatch:";
 		}




	 	if(!empty($errors))
	 	{
	 		echo "<b>Errors:</b><hr>";
	 		foreach ($errors as $key) {
	 			echo $key."<br>";
	 			// echo "<script type='text/javascript'>";
	 			// echo 'alert("echo($key)")';
	 			// echo "<br>";	 			
	 			// echo "</script>";
	 		}
	 		exit;
	 	}	

	 	if ($uploadOk == 0) 
		{
   			 echo "Sorry, your file was not uploaded.";
   			 exit;

		} 
		else
		 {
		    if (move_uploaded_file($_FILES["fileToupload"]["tmp_name"], $target_file))
		    {
		        $pic = $target_file; 
		    } 
		    else
		    {
		        echo "Sorry, there was an error uploading your file.";
		        exit;
		    }
		}


	 	// echo "$fname" . "<br>";
	 	// echo "$lname" . "<br>";
	 	// echo "$email" . "<br>";
	 	// echo "$number" . "<br>";
	 	// echo "$branch" . "<br>";
	 	// echo "$semester" . "<br>";
	 	// echo "$password" . "<br>";
	 	// echo "$pic" . "<br>";
		
	 	$sql= "INSERT INTO `stu_info`(`fname`, `lname`, `email`, `mobile`, `branch`, `semester`, `password`,`pic`) VALUES ('$fname','$lname','$email','$number','$branch','$semester','$password','$pic')";

	 	$rec1=mysqli_query($conn,$sql);

	 	if(!empty($rec1))
	 	{
	 		echo "<html>";
	 		echo "<body>";
	 			echo "<h1 align='center' id='h1header'> Account Created Sucessfully </h1>";
	 			echo "<div class='a1'>For More<a href='index.php' id='anchar1'>Log in</a></div>";
	 		echo "</body>";
	 		echo "</html>";

	 	}

?>
<!DOCTYPE html>
<html>
<head>
	<title></title>

	<style type="text/css">
	*{
		margin:0;
		padding: 0;
	}
	body{
		background-color: #f1f1f1;
	}
		#h1header{
			background-color: green;
		}
		.a1{
			margin-top: 20px;
			font-size: 30px;
			text-align: center;
		}
	</style>
</head>
<body>

</body>
</html>

