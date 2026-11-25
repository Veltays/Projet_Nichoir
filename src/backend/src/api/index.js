import express from "express";
import birdRoutes from "./bird.routes.js";

const apiRouter = express.Router();

apiRouter.use("/birds", birdRoutes);

export default apiRouter;
