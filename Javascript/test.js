hoisted(); // logs "foo" 

function hoisted() { console.log("foo"); }

var notHoisted = function() { console.log("bar"); };

var x = function(y) { return y * y; };

(function () { // statements 
})()

var t= function(){

}

var tt = function ss(){

}

function aa(){

}
(function kk(){
    
}

)
