
"use strict";

let ExecuteTrajectoryAction = require('./ExecuteTrajectoryAction.js');
let ExecuteTrajectoryActionFeedback = require('./ExecuteTrajectoryActionFeedback.js');
let ExecuteTrajectoryActionGoal = require('./ExecuteTrajectoryActionGoal.js');
let ExecuteTrajectoryActionResult = require('./ExecuteTrajectoryActionResult.js');
let ExecuteTrajectoryFeedback = require('./ExecuteTrajectoryFeedback.js');
let ExecuteTrajectoryGoal = require('./ExecuteTrajectoryGoal.js');
let ExecuteTrajectoryResult = require('./ExecuteTrajectoryResult.js');
let MoveGroupAction = require('./MoveGroupAction.js');
let MoveGroupActionFeedback = require('./MoveGroupActionFeedback.js');
let MoveGroupActionGoal = require('./MoveGroupActionGoal.js');
let MoveGroupActionResult = require('./MoveGroupActionResult.js');
let MoveGroupFeedback = require('./MoveGroupFeedback.js');
let MoveGroupGoal = require('./MoveGroupGoal.js');
let MoveGroupResult = require('./MoveGroupResult.js');
let MoveGroupSequenceAction = require('./MoveGroupSequenceAction.js');
let MoveGroupSequenceActionFeedback = require('./MoveGroupSequenceActionFeedback.js');
let MoveGroupSequenceActionGoal = require('./MoveGroupSequenceActionGoal.js');
let MoveGroupSequenceActionResult = require('./MoveGroupSequenceActionResult.js');
let MoveGroupSequenceFeedback = require('./MoveGroupSequenceFeedback.js');
let MoveGroupSequenceGoal = require('./MoveGroupSequenceGoal.js');
let MoveGroupSequenceResult = require('./MoveGroupSequenceResult.js');
let PickupAction = require('./PickupAction.js');
let PickupActionFeedback = require('./PickupActionFeedback.js');
let PickupActionGoal = require('./PickupActionGoal.js');
let PickupActionResult = require('./PickupActionResult.js');
let PickupFeedback = require('./PickupFeedback.js');
let PickupGoal = require('./PickupGoal.js');
let PickupResult = require('./PickupResult.js');
let PlaceAction = require('./PlaceAction.js');
let PlaceActionFeedback = require('./PlaceActionFeedback.js');
let PlaceActionGoal = require('./PlaceActionGoal.js');
let PlaceActionResult = require('./PlaceActionResult.js');
let PlaceFeedback = require('./PlaceFeedback.js');
let PlaceGoal = require('./PlaceGoal.js');
let PlaceResult = require('./PlaceResult.js');
let AllowedCollisionEntry = require('./AllowedCollisionEntry.js');
let AllowedCollisionMatrix = require('./AllowedCollisionMatrix.js');
let AttachedCollisionObject = require('./AttachedCollisionObject.js');
let BoundingVolume = require('./BoundingVolume.js');
let CartesianPoint = require('./CartesianPoint.js');
let CartesianTrajectory = require('./CartesianTrajectory.js');
let CartesianTrajectoryPoint = require('./CartesianTrajectoryPoint.js');
let CollisionObject = require('./CollisionObject.js');
let ConstraintEvalResult = require('./ConstraintEvalResult.js');
let Constraints = require('./Constraints.js');
let ContactInformation = require('./ContactInformation.js');
let CostSource = require('./CostSource.js');
let DisplayRobotState = require('./DisplayRobotState.js');
let DisplayTrajectory = require('./DisplayTrajectory.js');
let GenericTrajectory = require('./GenericTrajectory.js');
let Grasp = require('./Grasp.js');
let GripperTranslation = require('./GripperTranslation.js');
let JointConstraint = require('./JointConstraint.js');
let JointLimits = require('./JointLimits.js');
let KinematicSolverInfo = require('./KinematicSolverInfo.js');
let LinkPadding = require('./LinkPadding.js');
let LinkScale = require('./LinkScale.js');
let MotionPlanDetailedResponse = require('./MotionPlanDetailedResponse.js');
let MotionPlanRequest = require('./MotionPlanRequest.js');
let MotionPlanResponse = require('./MotionPlanResponse.js');
let MotionSequenceItem = require('./MotionSequenceItem.js');
let MotionSequenceRequest = require('./MotionSequenceRequest.js');
let MotionSequenceResponse = require('./MotionSequenceResponse.js');
let MoveItErrorCodes = require('./MoveItErrorCodes.js');
let ObjectColor = require('./ObjectColor.js');
let OrientationConstraint = require('./OrientationConstraint.js');
let OrientedBoundingBox = require('./OrientedBoundingBox.js');
let PlaceLocation = require('./PlaceLocation.js');
let PlannerInterfaceDescription = require('./PlannerInterfaceDescription.js');
let PlannerParams = require('./PlannerParams.js');
let PlanningOptions = require('./PlanningOptions.js');
let PlanningScene = require('./PlanningScene.js');
let PlanningSceneComponents = require('./PlanningSceneComponents.js');
let PlanningSceneWorld = require('./PlanningSceneWorld.js');
let PositionConstraint = require('./PositionConstraint.js');
let PositionIKRequest = require('./PositionIKRequest.js');
let RobotState = require('./RobotState.js');
let RobotTrajectory = require('./RobotTrajectory.js');
let TrajectoryConstraints = require('./TrajectoryConstraints.js');
let VisibilityConstraint = require('./VisibilityConstraint.js');
let WorkspaceParameters = require('./WorkspaceParameters.js');

module.exports = {
  ExecuteTrajectoryAction: ExecuteTrajectoryAction,
  ExecuteTrajectoryActionFeedback: ExecuteTrajectoryActionFeedback,
  ExecuteTrajectoryActionGoal: ExecuteTrajectoryActionGoal,
  ExecuteTrajectoryActionResult: ExecuteTrajectoryActionResult,
  ExecuteTrajectoryFeedback: ExecuteTrajectoryFeedback,
  ExecuteTrajectoryGoal: ExecuteTrajectoryGoal,
  ExecuteTrajectoryResult: ExecuteTrajectoryResult,
  MoveGroupAction: MoveGroupAction,
  MoveGroupActionFeedback: MoveGroupActionFeedback,
  MoveGroupActionGoal: MoveGroupActionGoal,
  MoveGroupActionResult: MoveGroupActionResult,
  MoveGroupFeedback: MoveGroupFeedback,
  MoveGroupGoal: MoveGroupGoal,
  MoveGroupResult: MoveGroupResult,
  MoveGroupSequenceAction: MoveGroupSequenceAction,
  MoveGroupSequenceActionFeedback: MoveGroupSequenceActionFeedback,
  MoveGroupSequenceActionGoal: MoveGroupSequenceActionGoal,
  MoveGroupSequenceActionResult: MoveGroupSequenceActionResult,
  MoveGroupSequenceFeedback: MoveGroupSequenceFeedback,
  MoveGroupSequenceGoal: MoveGroupSequenceGoal,
  MoveGroupSequenceResult: MoveGroupSequenceResult,
  PickupAction: PickupAction,
  PickupActionFeedback: PickupActionFeedback,
  PickupActionGoal: PickupActionGoal,
  PickupActionResult: PickupActionResult,
  PickupFeedback: PickupFeedback,
  PickupGoal: PickupGoal,
  PickupResult: PickupResult,
  PlaceAction: PlaceAction,
  PlaceActionFeedback: PlaceActionFeedback,
  PlaceActionGoal: PlaceActionGoal,
  PlaceActionResult: PlaceActionResult,
  PlaceFeedback: PlaceFeedback,
  PlaceGoal: PlaceGoal,
  PlaceResult: PlaceResult,
  AllowedCollisionEntry: AllowedCollisionEntry,
  AllowedCollisionMatrix: AllowedCollisionMatrix,
  AttachedCollisionObject: AttachedCollisionObject,
  BoundingVolume: BoundingVolume,
  CartesianPoint: CartesianPoint,
  CartesianTrajectory: CartesianTrajectory,
  CartesianTrajectoryPoint: CartesianTrajectoryPoint,
  CollisionObject: CollisionObject,
  ConstraintEvalResult: ConstraintEvalResult,
  Constraints: Constraints,
  ContactInformation: ContactInformation,
  CostSource: CostSource,
  DisplayRobotState: DisplayRobotState,
  DisplayTrajectory: DisplayTrajectory,
  GenericTrajectory: GenericTrajectory,
  Grasp: Grasp,
  GripperTranslation: GripperTranslation,
  JointConstraint: JointConstraint,
  JointLimits: JointLimits,
  KinematicSolverInfo: KinematicSolverInfo,
  LinkPadding: LinkPadding,
  LinkScale: LinkScale,
  MotionPlanDetailedResponse: MotionPlanDetailedResponse,
  MotionPlanRequest: MotionPlanRequest,
  MotionPlanResponse: MotionPlanResponse,
  MotionSequenceItem: MotionSequenceItem,
  MotionSequenceRequest: MotionSequenceRequest,
  MotionSequenceResponse: MotionSequenceResponse,
  MoveItErrorCodes: MoveItErrorCodes,
  ObjectColor: ObjectColor,
  OrientationConstraint: OrientationConstraint,
  OrientedBoundingBox: OrientedBoundingBox,
  PlaceLocation: PlaceLocation,
  PlannerInterfaceDescription: PlannerInterfaceDescription,
  PlannerParams: PlannerParams,
  PlanningOptions: PlanningOptions,
  PlanningScene: PlanningScene,
  PlanningSceneComponents: PlanningSceneComponents,
  PlanningSceneWorld: PlanningSceneWorld,
  PositionConstraint: PositionConstraint,
  PositionIKRequest: PositionIKRequest,
  RobotState: RobotState,
  RobotTrajectory: RobotTrajectory,
  TrajectoryConstraints: TrajectoryConstraints,
  VisibilityConstraint: VisibilityConstraint,
  WorkspaceParameters: WorkspaceParameters,
};
