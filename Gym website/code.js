function validate_admin(){
    var username=document.getElementById("username").value;
    var password=document.getElementById("password").value;
    if (username=="admin" && password=="password1"){
        window.location.href = 'Admin.html';
    }
    else{
        alert("login failed");
        return false;
    }
}
function validate_user(){
    var username=document.getElementById("username").value;
    var password=document.getElementById("password").value;
    if (username=="user" && password=="password2"){
        window.location.href = 'home.html';
    }
    else{
        alert("login failed");
        return false;
    }
}