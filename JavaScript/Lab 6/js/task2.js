window.addEventListener("mousemove", function () {
    let divs = document.querySelectorAll("div");
    for (let i = 0; i < divs.length; i++) {
        divs[i].onclick = function () {
            if (!this.className.includes("clicked")) {
                let newDiv = document.createElement("div");
                newDiv.className = this.className;
                document.body.append(newDiv);
                this.className += " clicked";
            }

        }
    }
});