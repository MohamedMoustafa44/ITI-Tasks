const urlParams = new URLSearchParams(window.location.search);

if(urlParams.get("name"))
{
    document.querySelector("p[id = name]").innerHTML = "Hello " + urlParams.get("name");
}
if(urlParams.get("age"))
{
    document.querySelector("p[id = age]").innerHTML = `You are ${urlParams.get("age")} years old`
}