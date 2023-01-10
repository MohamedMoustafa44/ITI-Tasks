window.addEventListener("load", function () {
    let eggImage = document.querySelector("img[alt = egg]");
    let basketImage = document.querySelector("img[alt = basket]");

    window.addEventListener("mousemove", function(event){
        if(event.x < (innerWidth - 0.5*basketImage.width))
        {
            basketImage.style.left = event.x - 0.5*basketImage.width;
        }
    });



    eggImage.style.left = Math.random() * 50 * 29 + "px";
    
    const moveBot = function (imageObject, bottom) {
        let id = setInterval(function () {
            imageObject.style.bottom = bottom + "%"; 
            bottom -= 1;
            if(bottom == 10 && (parseInt(imageObject.style.left) + parseInt(imageObject.width)) >= basketImage.width && (parseInt(imageObject.style.left) + parseInt(imageObject.width)) <= (parseInt(basketImage.style.left) + parseInt(basketImage.width)))
            {
                    imageObject.style.display = "none";
                    clearInterval(id);
            }
            else if( bottom == 0)
            {
                clearInterval(id);
                imageObject.src = "resources/imgs/Uovo_sorridente.png";
            }
            

        }, 50);//eof inetrval

    }
    moveBot(eggImage, 88);



});