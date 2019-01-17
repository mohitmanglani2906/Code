<!DOCTYPE html>
<html>
<head>
	<title>Delete</title>
<?php
	session_start();
	$dmob=$_SESSION['mob'];
	$conn=mysqli_connect("localhost","root","","studentdetails");
	$del ="DELETE FROM `stu_info` WHERE '$dmob'";
	$res = mysqli_query($conn,$del);
	echo '<script>';
		echo 'alert(""Account Deleted!!)';
	echo '</script>';
	header("location: index.php");

?>

<!-- </head>
<body>
	<script type="text/javascript">
		var conf = confirm("Are you sure?");
		if(conf)
		{
			alert("DELETED");
			alert('<?php echo date("Y/m/d"); ?>');


		}
		else
		{
				alert("NOT DELETED");
		}
	</script>
</body>
</html> -->




<!-- <?php
	session_start();
	$conn=mysqli_connect("localhost","root","","studentdetails");
	$dmob=$_SESSION['mob'];
	if ($_SESSION['mob'] == '')
	{
		header("location:index.php");
	}
	echo '<a href="loggedin.php">go back</a>';
	echo '<script>
			var conf= confirm("Are you sure you want to delete an account?");
			if(conf)
			{
				<?php

					$del = "DELETE FROM `stu_info` WHERE mobile = $dmob";
					$res= mysqli_query($conn,$del); 
					header("location:index.php");
				?>
			}
			else
			{
				window.location="loggedin.php";
			}
			
		</script>';
?>
 -->