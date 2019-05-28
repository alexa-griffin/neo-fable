import * as PIXI from "pixi.js" 

const view = document.createElement("canvas")

const pixiApp = new PIXI.Application({
  width: window.innerWidth,
  height: window.innerHeight,
  view: view
})

const stage = pixiApp.stage

export {
  pixiApp,
  stage,
  view
}