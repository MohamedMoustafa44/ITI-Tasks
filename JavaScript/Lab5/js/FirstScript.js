console.log(document.getElementsByTagName("img"));
console.log(document.querySelectorAll("img"));
console.log(document.querySelectorAll("select[name = City] option"));
console.log(document.querySelectorAll("table")[1].getElementsByTagName("td"));
console.log(document.getElementsByClassName("bGrey fontBlue"));



let id = setInterval(()=>{
    let date = new Date();
    document.title = date.toLocaleString();
}, 1000);


let imageObject = document.images;
let timerid = function(imageObject)
{
    let count = 1;
    let id = setInterval(()=>{
    
            count++;
            if(count>8) count=1;
            imageObject[0].src=`resources/img/${count}.jpg`;
    },1000);
    return id;
}

let stop = function(image)
{
    clearInterval(image);
}

let starter = timerid(imageObject);

