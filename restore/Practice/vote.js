let yesVotes = 0;
let noVotes = 0;

function vote(vote) {
    // clicked on a vote button
    if (vote === "yes")
    {
        // voted yes
        yesVotes++;
        document.getElementById("yes").innerText = "Yes: " + yesVotes;
    }
    else if (vote === "no")
    {
        // voted no
        noVotes++;
        document.getElementById("no").innerText = "No: " + noVotes;
    }
}

function reset() {
    // reset votes
    yesVotes = 0;
    noVotes = 0;
    document.getElementById("yes").innerText = "Yes: 0";
    document.getElementById("no").innerText = "No: 0";
}