import Layer from "./Layer"

export default class Application {
  private layerstack: Layer[]
  private canvas: HTMLCanvasElement
  
  public ctx: CanvasRenderingContext2D

  constructor() {
    this.layerstack = []

    this.canvas = document.createElement("canvas")
    this.ctx = this.canvas.getContext("2d")
  }

  init() {
    document.body.appendChild(this.canvas)
  }

  start() {
    requestAnimationFrame(_ => this.start())
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