window.addEventListener("load", function(){
    let textVal = document.querySelector("input[name = task]");
    let addBtn = document.querySelector("input[value = Add]");
    let taskTable = document.querySelector("tbody");
    let reset = document.querySelector("input[value = Reset]");
    let doneAll = document.querySelector("input[value = Done]")

    taskTable.addEventListener("change", function()
    {
        for(let i = 0; i < taskTable.querySelectorAll("input[type = checkbox]").length; i++)
        {
            if(taskTable.querySelectorAll("input[type = checkbox]")[i].checked)
            {
                taskTable.querySelectorAll("tr")[i].querySelectorAll("td")[1].style.textDecoration = "line-through";
            }
            else
            {
                taskTable.querySelectorAll("tr")[i].querySelectorAll("td")[1].style.textDecoration = "none";
            }
        }
    });

    doneAll.addEventListener("click", function()
    {
        for(let i = 0; i < taskTable.querySelectorAll("input[type = checkbox]").length; i++)
        {
            taskTable.querySelectorAll("input[type = checkbox]").forEach(function(box)
            {
                box.checked = true;
                box.parentElement.parentElement.querySelectorAll("td")[1].style.textDecoration = "line-through";
            });
        }
    });

    reset.addEventListener("click", function()
    {
        for(let i = 0; i < taskTable.querySelectorAll("tr").length; i++)
        {
            taskTable.querySelectorAll("tr").forEach(function(row)
            {
                row.remove();
            });
        }
    });
    
    addBtn.addEventListener("click", function()
    {
        let row = document.createElement("tr");
        let checking = document.createElement("td");
        let checkBox = document.createElement("input");
        checkBox.type = "checkbox";
        checking.append(checkBox);
        let taskName = document.createElement("td");
        taskName.innerText = textVal.value;
        let deleting = document.createElement("td");
        let delBtn = document.createElement("button");
        delBtn.innerText = "Delete";
        delBtn.onclick = function()
        {
            this.parentElement.parentElement.remove();
        }
        deleting.append(delBtn);
        row.append(checking, taskName, deleting);
        taskTable.append(row);
        
    });
});