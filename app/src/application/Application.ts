import Layer from "./Layer"
import Store from "./Store"


export default class Application {
  private layerstack: Layer[]
  private store: Store
      
  private canvas: HTMLCanvasElement
  public ctx: CanvasRenderingContext2D

  constructor() {
    this.layerstack = []

    this.canvas = document.createElement("canvas")
    this.ctx = this.canvas.getContext("2d")

    this.store = new Store({
      num: 0,
      data: {
        suzen: ""
      }
    })
  }

  init() {
    document.body.appendChild(this.canvas)
  }

  setState(delta: object) {
    this.store.set(delta)
    console.log(this.store)
  }

  start() {
    // requestAnimationFrame(_ => this.start())
    this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height)
    this.layerstack.forEach(layer => {
      layer.onUpdate()
    })
  }

  pushLayer(layer: Layer) {
    layer.applyApplicationContext(this)
    layer.onMount()
    this.layerstack.push(layer)
  }
}