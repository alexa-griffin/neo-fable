type STLCallback = (oldVal: any, newVal: any) => void

interface StateChangeListener {
  key: string,
  callback: STLCallback
}

export { STLCallback, StateChangeListener }

export default class Store {
  private _state: object
  public state: object

  constructor(defaultValue: object) {
    this._state = defaultValue
    this.state = new Proxy(this._state, {
      defineProperty: (target: object, prop: string | number | symbol, desc: PropertyDescriptor): boolean => {
        console.error("%c do not try to mutate state directly!", 
                      "font-weight: bold; font-size: 32px")
        return false
      }
    })
  }

  set(deltas: object) {
    Object.entries(deltas).forEach(delta => {
      let keys = delta[0].split(".")
      let res = this._state
      for (let i = 0; i < keys.length - 1; i++) {
        if(!res[keys[i]]) res[keys[i]] = {}
        res = res[keys[i]]
      }
      res[keys[keys.length - 1]] = delta[1]
    })
  }
}