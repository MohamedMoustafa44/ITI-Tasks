window.addEventListener("load", function(){
    let red = document.getElementById("red");
    let green = document.getElementById("green")
    let blue = document.getElementById("blue");
    let text = document.querySelector("h2");

    red.addEventListener("change", function(){
        text.style.color = `rgb(${red.value}, ${green.value}, ${blue.value})`;
    });

    green.addEventListener("change", function(){
        text.style.color = `rgb(${red.value}, ${green.value}, ${blue.value})`;
    });
    
    blue.addEventListener("change", function(){
        text.style.color = `rgb(${red.value}, ${green.value}, ${blue.value})`;
    });
});