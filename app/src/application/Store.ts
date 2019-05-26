
export default class Store {
  state: object

  constructor(defaultValue: object) {
    this.state = defaultValue
  }

  set(deltas: object) {
    Object.entries(deltas).forEach(delta => {
      let keys = delta[0].split(".")
      let res = this.state
      for (let i = 0; i < keys.length - 1; i++) {
        if(!res[keys[i]]) res[keys[i]] = {}
        res = res[keys[i]]
      }
      res[keys[keys.length - 1]] = delta[1]
      // console.log(this.access(delta[0]))// = delta[1]
    })
  }
}