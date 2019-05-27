function access(key, obj) {
  if(obj[key]) return obj[key]
  let keys: string = key.split(".")
  let res = obj

  for (let i = 0; i < keys.length; i++) {
    res = res[keys[i]]
    if(typeof res !== "object" && i < keys.length - 1) {
      res = null
      break
    }
  }
  return res
}

export {
  access,
}