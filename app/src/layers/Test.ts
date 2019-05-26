import Layer from "../application/Layer"


export default class Test extends Layer {
  constructor() {
    super()
  }

  onUpdate() {
    this.ctx.fillRect(20, 20, 100, 100)
  }
}