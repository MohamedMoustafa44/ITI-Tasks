$(()=>{
    let textField = $("input[type = text]");
    let addBtn = $("button");

    $(document).on('click','.delete',function(){
        $(this).parent().remove();
       })
       $(document).on('click','.done',function(){
        $(this).parent().toggleClass("TaskDone");
       })

    addBtn.click(e=>{
        $(`<div>
        <input class="task" type="text" value="${textField.val()}" disabled>
        <button class="done">Done</button>
        <button class="delete">Delete</button>
        </div>`).appendTo(".tasksBox");
        
        
    });
});