let toPascalCase = function(strInput)
{
    let localStr = "";
    let localArrStr = strInput.split(" ");
    for(let i = 0; i < localArrStr.length; i++)
    {
        localStr += localArrStr[i][0].toUpperCase();
        localStr += localArrStr[i].slice(1);
        localStr += " ";
        
    }
    return localStr;
}
