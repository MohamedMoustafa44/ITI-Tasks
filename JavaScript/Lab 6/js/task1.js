window.addEventListener("load", function () {
    let addBtn = document.querySelector("input[value = Add]");
    let stdName = document.querySelector("input[name = studentName]");
    let stdGrade = document.querySelector("input[name = studentGrade]");
    let stdsTable = document.querySelectorAll("table")[1];
    let names = new Array();
    let filter = document.querySelectorAll("select")[1];




    stdGrade.addEventListener("keypress", function (event) {
        if (isNaN(event.key)) {
            event.preventDefault();
            document.getElementById("gardeError").style.display = "inline";
        }
        else {
            document.getElementById("gardeError").style.display = "none";
        }

    });

    filter.addEventListener("change", function () {
        if (filter.value == "all") {
            for (let i = 0; i < stdsTable.querySelectorAll("tr").length; i++) {

                stdsTable.querySelectorAll("tr")[i].style.display = "revert";
            }
        }
        else {
            if (filter.value == "success") {
                for (let i = 0; i < stdsTable.querySelectorAll("tr").length; i++) {
                    if (parseInt(stdsTable.querySelectorAll("tr")[i].querySelectorAll("td")[1].innerText) < 60) {
                        stdsTable.querySelectorAll("tr")[i].style.display = "none";
                    }
                    else{
                        stdsTable.querySelectorAll("tr")[i].style.display = "revert";
                    }
                }
            }
            
            else if (filter.value == "fail") {
                for (let i = 0; i < stdsTable.querySelectorAll("tr").length; i++) {
                    if (parseInt(stdsTable.querySelectorAll("tr")[i].querySelectorAll("td")[1].innerText) > 60) {
                        stdsTable.querySelectorAll("tr")[i].style.display = "none";
                    }
                    else{
                        stdsTable.querySelectorAll("tr")[i].style.display = "revert";
                    }
                }
            }
        }
    });






    addBtn.onclick = function () {
        if (stdName.value && !names.includes(stdName.value.toLowerCase()) && parseInt(stdGrade.value) <= 100) {
            let department = document.querySelector("input[name = Department]:checked").value;
            let row = document.createElement("tr");
            row.classList.add(department);
            let nameData = document.createElement("td");
            nameData.innerText = toPascalCase(stdName.value);
            nameData.className = stdName.value.toLowerCase();
            row.append(nameData);
            let gradeData = document.createElement("td");
            if (stdGrade.value) {

                gradeData.innerText = stdGrade.value;
            }
            else {
                gradeData.innerText = "0";
            }
            row.append(gradeData);
            let delBtn = document.createElement("button");
            delBtn.innerText = "Delete";
            delBtn.onclick = function () {

                this.parentElement.parentElement.remove();
                let index = names.indexOf(this.parentElement.parentElement.querySelector("td").className);
                names.splice(index, 1);
            }
            let delBtnTd = document.createElement("td");
            delBtnTd.append(delBtn);
            row.append(delBtnTd);
            stdsTable.append(row);
            names.push(row.querySelector("td").className);

            document.getElementById("nameError").style.display = "none";
            document.getElementById("gardeError").style.display = "none";

        }
        else {

            if (!stdName.value) {
                document.getElementById("nameError").innerText = "Enter name!";
                document.getElementById("nameError").style.display = "inline";
            }
            else {

                if (names.includes(stdName.value.toLowerCase())) {
                    document.getElementById("nameError").innerText = "Name repeated!";
                    document.getElementById("nameError").style.display = "inline";
                }
                else {
                    document.getElementById("nameError").style.display = "none";
                }
                if (parseInt(stdGrade.value) > 100) {
                    document.getElementById("gardeError").style.display = "inline";
                }

            }

        }
    }


});
