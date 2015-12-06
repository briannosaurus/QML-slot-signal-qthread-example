.pragma library

function func() {

}

WorkerScript.onMessage = function(message) {
    WorkerScript.sendMessage({ 'reply': 'Mouse is at ' + message.x + ',' + message.y })
    console.log("QML WORKER: In Worker Function")
}
