function sockMerchant(n, ar) {
    // Write your code here
    let map = new Map();
    for(let a of ar) {
        if(map.has(a)) {
            let lastCount = map.get(a);
            //++lastCount
            map.set(a, ++lastCount);

            console.log(`${a} already exists`);
            console.log(`${a} : ${map.get(a)}`);
        }
        else {
            map.set(a, 1);
            console.log(`${a} added with value 1`);
        }
    }

    let pairsOfSock = 0;
    for(let [K, V] of map.entries()) {
        let res = Math.floor(V/2);
        pairsOfSock += res;
    }
    
    return pairsOfSock;
}

console.log(sockMerchant(9, [10, 20, 20, 10, 10, 30, 50, 10, 20]));