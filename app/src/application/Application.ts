import Layer from "./Layer"

export default class Application {
  private layerstack: Layer[]
  
  constructor() {
    this.layerstack = []
  }

  init() {

  }

  start() {
    requestAnimationFrame(_ => this.start())
    this.layerstack.forEach(layer => {
      layer.onUpdate()
    })
  }

  pushLayer(layer: Layer) {
    this.layerstack.push(layer)
  }
}