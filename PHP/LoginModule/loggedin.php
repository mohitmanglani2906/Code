<?php
	session_start();
	$conn=mysqli_connect("localhost","root","","studentdetails");
	//mysql_select_db("studentdetails");
	if ($_SESSION['mob'] == '')
	{
		header("location:index.php");
	}
	$lmob=$_SESSION['mob'];
	$sel="select * from stu_info where mobile='$lmob'";
	$ex=mysqli_query($conn,$sel);
	$row=mysqli_fetch_array($ex);
	
?>	


<!DOCTYPE html>
<html>
<head>
	<title>Welcome</title>
	<meta charset="UTF-8">
	<link rel="stylesheet" type="text/css" href="mystyle.css">
	<script type="text/javascript">
		function delete_account()
		{
			
			var conf= confirm("Are you sure?");
			if(conf)
			{
				window.location='delete.php';
			}	
			
		
			
			
		}
	</script>
	</head>
<body>

	<?php	

		$imagepath = $row['pic'];
			
			echo '<div class="header"> ';
			echo '<ul class="profile">';
				echo '<li id="account"><a href="#about" id="uname">' . $row["fname"] . '</a></li>';
				echo '<li><img src=" ' . $imagepath . ' "</li>';
			echo '</ul>';
			echo '</div>';	

			

			echo '<div class="middle">';
			echo '<form method="post" action="" align="center" class="formmiddle">';
			echo '<input type="submit" name="getdata" value="Get Your Information" class="middleinput" id="getdata" class="getdata"><br>';
			echo '<input type="submit" name="update" value="Update your info." id="update"><br>';	
			echo '<input type="submit" name="logout" value="Logout"  id="logout"><br>';
			/*echo '<input type="button" name="delete" value="Delete" id="delete" onclick="delet_account(<?php echo $lmob;?>)">';*/
			echo '<a type="button" onclick="delete_account()" id="delete">Delete Account</a>';
			
			

			
	

			if(isset($_POST['getdata']))
			{
				$sql1 = "SELECT `fname`,`lname`,`email`,`mobile`,`branch`,`semester`,`pic` FROM `stu_info` WHERE mobile='$lmob'";
				$rec3=mysqli_query($conn,$sql1);
				$row1=mysqli_fetch_assoc($rec3);
				$imagepath1 = $row1['pic'];

				echo '<table class="tb1" id="tb1" >';
				echo  '<tr>
						<td>First Name</td>
						<td>Last Name</td>
						<td>Email id</td>
						<td>Mobile no</td>
						<td>Branch</td>
						<td>Semester</td>
						<td>Pic</td>
					</tr>';	

				echo '<tr>
						<td> ' . $row1['fname'] . ' </td>
						<td> ' . $row1['lname'] . ' </td>
						<td> ' . $row1['email'] . '   </td>
						<td> ' . $row1['mobile'] . '  </td>
						<td> ' . $row1['branch'] . ' </td>
						<td> ' . $row1['semester'] . ' </td>
						<td> <img src=" ' . $imagepath1 . ' " style="margin-top:10px;"></td>
						</tr>';	
					{
					
				}	

			}

			if(isset($_POST['update']))	
			{
				header("location: update.php");
			}
			if(isset($_POST['logout']))
			{
				header("location:logout.php");
			}		
			if(isset($_POST['delete']))
			{
				header("location: delete.php");
				
			}


		echo '</form>';	

		echo '<hr style="margin-top: 30px;width:90%;margin-left:70px;">';	

			
?>
	
		
	</div>	
</html>




