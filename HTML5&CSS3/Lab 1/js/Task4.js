window.addEventListener("load", function () {
    let canv = document.getElementById("canv")
    let ctx = canv.getContext("2d");
    let dim = 0;
    let lineExpand = setInterval(() => {
        ctx.beginPath();
        ctx.moveTo(0, 0);
        if (dim <= 500) {
            ctx.lineTo(dim, dim);
            dim++;
            ctx.lineWidth = 5;
            ctx.stroke();
        }
        else{
            Swal.fire({
                text: 'Animation End',
                icon: 'success',
                confirmButtonText: 'Cool',
              })
            clearInterval(lineExpand);
        }
    }, 50);
});