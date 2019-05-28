import * as PIXI from "pixi.js"

import Layer from "../application/Layer"

export default class Test extends Layer {
  gtx: PIXI.Graphics

  constructor() {
    super()

    this.gtx = new PIXI.Graphics()
  }

  onMount() {
    this.stage(this.gtx)
  }

  onUpdate(dT: number) {
    this.gtx.beginFill(0xffffff)
      .drawRect(20, 20, 100, 100)
      .endFill()
    this.setState({ 
      num: this.getState().num + 1,
    })
  }
}