import Layer from "../application/Layer"


export default class Test extends Layer {
  constructor() {
    super()
  }

  onMount() {
    
  }

  onUpdate() {
    this.ctx.fillRect(20, 20, 100, 100)
    this.setState({ 
      num: 1,
      ["data.kevin"]: "heck"
    })
  }
}