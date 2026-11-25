import express from "express";
import { listBirds } from "../controller/bird.controller.js";

const router = express.Router();

router.get("/", listBirds);
router.post("/add", addBird);


export default router;
