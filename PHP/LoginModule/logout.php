<?php
session_start();
unset($_SESSION['mob']);
unset($_SESSION['pwd']);
session_destroy();
header("location:index.php");
?>