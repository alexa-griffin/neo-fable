import Layer from "./Layer"
import Store, { STLCallback, StateChangeListener } from "./Store"

import { access } from "../util/util"

export default class Application {
  private layerstack: Layer[]
  private store: Store
      
  private canvas: HTMLCanvasElement
  public ctx: CanvasRenderingContext2D

  private listeners: StateChangeListener[]

  constructor() {
    this.layerstack = []
    this.listeners = []

    this.canvas = document.createElement("canvas")
    this.canvas.width = window.innerWidth
    this.canvas.height = window.innerHeight

    this.ctx = this.canvas.getContext("2d")

    this.store = new Store({
      num: 0,
      data: {
        suzen: ""
      }
    })
  }

  // state management
  setState(deltas: object): void {
    const prevState: object = { ...this.store.state }
    this.store.set(deltas)
    this.listeners.forEach(listener => {
      let dAccess: any = access(listener.key, deltas)
      if (dAccess !== null && typeof(dAccess) !== "undefined") {
        listener.callback(prevState, this.store.state)
      } else {
        let dKeys: string[] = Object.keys(deltas)
        for(let i = 0; i < dKeys.length; i++) {
          if(dKeys[i].indexOf(listener.key) === 0) {
            listener.callback(prevState, this.store.state)
          }
        }
      }
    })
  }
  
  getState(): object {
    return this.store.state
  }
  
  addStateListener(key: string, callback: STLCallback): void {
    this.listeners.push({ key: key, callback: callback })
  }


  init(): void {
    document.body.appendChild(this.canvas)
  }

  start(): void {
    // requestAnimationFrame(_ => this.start())
    this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height)
    this.layerstack.forEach(layer => {
      layer.onUpdate()
    })
  }

  pushLayer(layer: Layer): void {
    layer.applyApplicationContext(this)
    layer.onMount()
    this.layerstack.push(layer)
  }
}