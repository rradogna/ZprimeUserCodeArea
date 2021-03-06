//=========================================================================  
////             Make the pat tuple for Ele & Mu analysis                   =
////                (works only on miniaod formate)                         =   
////                         CMSSW_7_2_0                                    =
////                                                                        =
////                    Author: Sherif Elgammal                             =
////                                                                        =
////                         14/01/2015                                     =
////=========================================================================
#ifndef MyCodeArea_Analyzer_MakeMuonElectronPatTuple_h
#define MyCodeArea_Analyzer_MakeMuonElectronPatTuple_h
#include <memory>
// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/EgammaReco/interface/BasicCluster.h"
#include "DataFormats/EgammaReco/interface/BasicClusterFwd.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterLazyTools.h"
//#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/PATObject.h" 
#include "DataFormats/PatCandidates/interface/CompositeCandidate.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/EgammaReco/interface/BasicCluster.h"
#include "DataFormats/EgammaReco/interface/BasicClusterFwd.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterLazyTools.h"
#include "Geometry/CaloEventSetup/interface/CaloTopologyRecord.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/CaloTopology/interface/CaloTopology.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include <FWCore/Framework/interface/ESHandle.h>
//#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
//====================== Get PixelMatchGsfElectronCollection =========
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronCore.h"
#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrackFwd.h"
#include <DataFormats/EgammaCandidates/interface/GsfElectron.h>
//====================== Get PixelMatchGsfElectronCollection =========
#include "RecoCaloTools/Navigation/interface/CaloNavigator.h"
#include "CLHEP/Geometry/Transform3D.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/CaloTopology/interface/CaloTopology.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "Geometry/EcalAlgo/interface/EcalBarrelGeometry.h"
//#include "DQMOffline/JetMET/interface/CaloMETAnalyzer.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/METReco/interface/CaloMET.h"
#include "DataFormats/METReco/interface/CaloMETCollection.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"
#include "DataFormats/CaloTowers/interface/CaloTowerDetId.h"
#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/METReco/interface/SpecificCaloMETData.h"
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/METReco/interface/CorrMETData.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
//#include "FWCore/ParameterSet/interface/InputTag.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "RecoLocalCalo/EcalRecAlgos/interface/EcalSeverityLevelAlgo.h"

#include "DataFormats/METReco/interface/CaloMET.h"
#include "DataFormats/METReco/interface/CaloMETFwd.h"
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/METReco/interface/METFwd.h"
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/PFMETFwd.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"
#include "DataFormats/METReco/interface/PFMET.h"
//==================== start a part for Jet ================================
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/JetReco/interface/PFJet.h"
//==================== end a part for Jet ================================
//==================== start a part for photons ==========================
#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"
#include "RecoEgamma/EgammaTools/interface/ConversionTools.h"
//#include "tmp/CaloGeometryBuilder/interface/CaloGeometryBuilder.h"
#include <DataFormats/MuonReco/interface/Muon.h>
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/Common/interface/RefCore.h"
#include "FWCore/Utilities/interface/EDMException.h"
#include "FWCore/Utilities/interface/TypeID.h"

#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/RecoCandidate/interface/IsoDeposit.h"
#include "DataFormats/RecoCandidate/interface/IsoDepositFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"
 
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"


#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"


#include "RecoMuon/TrackingTools/interface/MuonServiceProxy.h"

#include "DataFormats/Math/interface/deltaR.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h" 
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerTypeDefs.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "CommonTools/TriggerUtils/interface/GenericTriggerEventFlag.h"
 
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h" 
#include "DataFormats/MuonReco/interface/MuonEnergy.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"

// Trigger
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PATObject.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/PatCandidates/interface/TriggerFilter.h"
#include "DataFormats/Math/interface/deltaR.h"


//====================== end a part for photons ==========================
#include <vector>
#include <set>
#include <stdio.h>
#include "TProfile.h"
#include "TProfile2D.h"
//#include <iostream.h>
//#include <ostream.h>
//#include <fstream.h>
//#include <vector.h>
#include "TFile.h"
#include <math.h>
#include "TF2.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TLorentzVector.h"
#include "Math/LorentzVector.h"
#include "TTree.h"
#include "TMath.h"
#include "RecoEgamma/EgammaTools/interface/ConversionTools.h"
#include "DataFormats/EgammaCandidates/interface/Conversion.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrackFwd.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrack.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/Common/interface/RefToPtr.h"
#include "DataFormats/Math/interface/deltaPhi.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "RecoVertex/VertexPrimitives/interface/TransientVertex.h"


#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
class TFile;

//
// class declaration
//


class MakeMuonElectronPatTuple : public edm::EDAnalyzer {
   public:
      explicit MakeMuonElectronPatTuple( const edm::ParameterSet& );  //constructor
      ~MakeMuonElectronPatTuple();  //distructor
      virtual void analyze( const edm::Event&, const edm::EventSetup& );
      virtual void beginJob();
      virtual void endJob();
      bool PrimaryVertex(const reco::VertexCollection &vertices);
      void IntialValues();
      void PrimaryVertexTree(const reco::VertexCollection &vertices);
      void PatMuonTree(const edm::Event& evt,const edm::EventSetup& es);
      void PatElectronTree(const edm::Event& iEvent,const edm::EventSetup& es);
      //void GenParticleTree(const edm::Event& evt);
      //bool IsMuMatchedToHLTMu ( const reco::Muon &mu, std::vector<reco::Particle> HLTMu , double DR, double DPtRel);
      //void TriggerMatchingTree(const edm::Event& iEvent,const reco::MuonCollection* muons);
      void PatMuonMatchGenTree(const edm::Event& evt,const edm::EventSetup& es);
      void accessGenInfo(const edm::Event& evt,const edm::EventSetup& es);
      bool isAncestor(const reco::Candidate* ancestor, const reco::Candidate * particle);
      void TriggerMatchingTree(const edm::Event& iEvent,const edm::EventSetup& es);
      void MuonParticleFlowTree(const edm::Event& iEvent,const edm::EventSetup& es);
      void EBecalRecHitsTree(const edm::Event& iEvent,const edm::EventSetup& es);
      void EEecalRecHitsTree(const edm::Event& iEvent,const edm::EventSetup& es);
 private:

      TTree* mytree;
      //====================================================
      //
      //    Create variable for Nb of event,run,lumi
      //
      //====================================================
      GlobalPoint eventVertexPosition_;
      int Run;
      int Event;
      int lumi;
      int bunch;
      int event_runNo;
      int event_evtNo;
      int event_lumi;
      int event_bunch;
      int TotalNbEvents;
      int NbEventsPass;
      int nbTk;
      std::vector<int> NbEventsPassTrigger; 
      std::vector<int> NbEventsPassTriggerandPVcond;
      //==================================================
      //
      //      Create vectors for Electrons variables
      //
      //==================================================
      int NbElectrons;
      std::vector<int> Ele_nbElectrons;
      std::vector<bool> Ele_isEcalDrivenSeed;
      std::vector<bool> Ele_isPassConversionVeto;
      std::vector<int> Ele_charge;
      std::vector<int> Ele_nbOfMissingHits;
      std::vector<int> Ele_nbVtx;
      std::vector<float> Ele_Et;
      std::vector<float> Ele_EtFromCaloEn;
      std::vector<float> Ele_pt;
      std::vector<float> Ele_thetaSC;
      std::vector<float> Ele_etaSC;
      std::vector<float> Ele_phiSC;
      std::vector<float> Ele_energySC;
      std::vector<float> Ele_preshowerEnergySC;
      std::vector<float> Ele_thetaTrack;
      std::vector<float> Ele_etaTrack;
      std::vector<float> Ele_phiTrack;
      std::vector<float> Ele_hadronicOverEm;
      std::vector<float> Ele_deltaEtaInSC;
      std::vector<float> Ele_deltaPhiInSC;
      std::vector<float> Ele_sigmaIetaIeta;
      std::vector<float> Ele_e2x5Max;
      std::vector<float> Ele_e1x5;
      std::vector<float> Ele_e5x5;
      std::vector<float> Ele_e2x5MaxOver5x5;
      std::vector<float> Ele_e1x5Over5x5;
      std::vector<float> Ele_sigmaIetaIetaFull5x5;
      std::vector<float> Ele_e2x5MaxFull5x5;
      std::vector<float> Ele_e1x5Full5x5;
      std::vector<float> Ele_e5x5Full5x5;
      std::vector<float> Ele_e2x5MaxOver5x5Full5x5;
      std::vector<float> Ele_e1x5Over5x5Full5x5;
      std::vector<float> Ele_e2x5Right;
      std::vector<float> Ele_e2x5Left;
      std::vector<float> Ele_e2x5Top;
      std::vector<float> Ele_e2x5Bottom;
      std::vector<float> Ele_eMax;
      std::vector<float> Ele_eRight;
      std::vector<float> Ele_eLeft;
      std::vector<float> Ele_eTop;
      std::vector<float> Ele_eBottom;
      std::vector<float> Ele_dxy;
      std::vector<float> Ele_dz;
      std::vector<float> Ele_rhoIso;
      std::vector<float> Ele_fbrem;
      std::vector<float> Ele_EoverP;
      std::vector<float> Ele_Xposition;
      std::vector<float> Ele_Yposition;
      //------------- detector isolation -------------------------
      std::vector<float> Ele_EcalPlusHcald1iso;
      std::vector<float> Ele_dr03TkSumPt;
      std::vector<float> Ele_dr03EcalRecHitSumEt;
      std::vector<float> Ele_dr03HcalDepth1TowerSumEt;
      std::vector<float> Ele_dr03HcalDepth1TowerSumEtBc;
      std::vector<float> Ele_hcalDepth1OverEcal;
      std::vector<float> Ele_hcalDepth2OverEcal;
      std::vector<float> Ele_dr03HcalDepth2TowerSumEt;
      std::vector<float> Ele_hcalDepth2TowerSumEtNoVeto;
      std::vector<float> Ele_hcalDepth1TowerSumEtNoVeto;                       
      //------------- PF isolation from pat::ele -------------------------
      std::vector<float> Ele_pfSumPhotonEt;
      std::vector<float> Ele_pfSumChargedHadronPt;
      std::vector<float> Ele_pfSumNeutralHadronEt;
      std::vector<float> Ele_pfSumPUPt;
      std::vector<float> Ele_pfDeltaBeta;
      //==================================================
      //
      //           Create vectors for Muons variables
      //
      //==================================================
      int NbMuons;
      std::vector<int> Mu_nbMuon;
      std::vector<float> EtaMuon;
      std::vector<bool> Mu_isGlobalMuon;
      std::vector<bool> Mu_isHighPtMuon;
      std::vector<bool> Mu_isPF;
      std::vector<bool> Mu_isTrackerMuon;
      std::vector<float> Mu_dPToverPTBestTrack;
      std::vector<float> Mu_en;
      std::vector<float> Mu_pt;
      std::vector<float> Mu_eta;
      std::vector<float> Mu_phi;
      std::vector<float> Mu_et;
      std::vector<float> Mu_charge;      
      std::vector<float> Mu_normalizedChi2;
      std::vector<float> Mu_absdxyBestTrack;
      std::vector<float> Mu_absdzBestTrack;
      std::vector<float> Mu_absdxy;
      std::vector<float> Mu_absdz;
      std::vector<float> Mu_trackiso;
      std::vector<int> Mu_numberOfMatchedStations;
      std::vector<int> Mu_numberOfValidPixelHits;
      std::vector<int> Mu_numberOftrackerLayersWithMeasurement;
      std::vector<float> Mu_pfSumChargedHadronPt;
      std::vector<float> Mu_pfSumNeutralHadronEt;
      std::vector<float> Mu_PFSumPhotonEt;
      std::vector<float> Mu_pfSumPUPt;
      std::vector<float> Mu_calEnergy;
      std::vector<int> Mu_numberOfValidMuonHits;
      std::vector<float> Mu_emIso;
      std::vector<float> Mu_hadIso;
      std::vector<float> Mu_VTXnormalizedChi2;
      std::vector<float> Mu_vtxMass;
      std::vector<float> Mu_vtxTotalChi2;
      std::vector<float> Mu_vtxNormChi2;
      std::vector<float> Mu_ptcocktail;
      std::vector<int> Mu_nbofpv;
      std::vector<float> Mu_pxBestTrack;
      std::vector<float> Mu_pyBestTrack;
      std::vector<float> Mu_pzBestTrack;
      std::vector<float> Mu_pBestTrack;
      std::vector<float> Mu_etaBestTrack;
      std::vector<float> Mu_ptInnerTrack;
      std::vector<float> Mu_ptBestTrack;
      std::vector<float> Mu_phiBestTrack;
      std::vector<float> Mu_thetaBestTrack;
      std::vector<float> Mu_chargeBestTrack;
      std::vector<float> Mu_pfDeltaBeta;
      std::vector<float> Mu_patDeltaBeta;
      std::vector<float> Mu_ptTunePMuonBestTrack;
      //===================================================
      //
      //    Create vectors for gen particles variables
      //
      //===================================================
      int NbGenMuons;
      std::vector<int> iGen;
      std::vector<int> idGen;
      std::vector<int> statusGen; 
      std::vector<float> ptGen;
      std::vector<float> etaGen;
      std::vector<float> phiGen;
      std::vector<float> massGen;
      std::vector<int> chargeGen;
      std::vector<float> EnergyGen;
      std::vector<float> pxGen;
      std::vector<float> pyGen;
      std::vector<float> pzGen;
      std::vector<float> vxGen;
      std::vector<float> vyGen;
      std::vector<float> vzGen;
      std::vector<int> NbOfDaughters;
      std::vector<float> McZmass;
      std::vector<float> McZpt;
      std::vector<float> McZpx;
      std::vector<float> McZpy;
      std::vector<float> McZpz;
      std::vector<float> McZen;
      //====================================================
      //
      //   Create vectors for Pimary Vertice variables
      //
      //====================================================
      int value3_;
      std::vector<int> nbPv;
      std::vector<int> Nbdof;
      std::vector<float> PositionX;
      std::vector<float> PositionY;
      std::vector<float> PositionZ;
      std::vector<float> PositionRho;
      //=============================================================
      //
      //           Create Branchs for Muons match HLT variables
      //
      //=============================================================
      int nMuHLT;
      std::vector<int> MuHLTObj_nbObj;
      std::vector<float> MuHLTObj_pt;
      std::vector<float> MuHLTObj_eta;
      std::vector<float> MuHLTObj_phi;
      //=============================================================
      //      
      //                       Create Branchs for ecal rec hits
      //                  
      //=============================================================
      int nbRecHits;
      std::vector<int> ecal_iRechit;
      std::vector<float> ecal_EnRecHit;
      std::vector<float> ecal_EtaRecHit;
      std::vector<float> ecal_PhiRecHit;
      std::vector<int> ecal_RecoFlag;
      std::vector<bool> ecal_isSaturated;
      
      //=============================================================
      double maxAbsZ_;
      double maxd0_;
      int minNdof_;
      int NbGoodPv_;
      int BosonID_;
      std::string outputFile_; // output file
      edm::InputTag vertexSrc;
      edm::InputTag pfMuons_;
      edm::InputTag pfMuonToken_;
      edm::InputTag srcSelectedMuons_;  
      edm::InputTag srcPFCandidates_; 
      edm::InputTag theRecoLabel_;
      edm::InputTag PatElectronsrc_;
      edm::InputTag genParticlesColl_;
      edm::InputTag tokentracks_;
      edm::InputTag globalMuons_;
      edm::InputTag token_globalMuons;
      /// HLT TriggerResults EDProduct
      edm::InputTag inputTag_;
      /// HLT trigger names
      edm::TriggerNames triggerNames_;
      
      /// number of HLT trigger paths requested in configuration
      unsigned int n_;
      bool firstevent_;
      // PG and FRC 06-07-11 try to reduce printout!
      bool debug;
      /// list of required HLT triggers by HLT name
      std::vector<std::string > HLTPathsByName_;
      /// list of required HLT triggers by HLT index
      std::vector<unsigned int> HLTPathsByIndex_;
      edm::InputTag triggerEvent;
      std::string triggerFilter;
      std::vector<std::string> triggerFilter_asym;
      edm::InputTag muonLabel;
      
      //new inputs for pat for miniaod
      edm::InputTag reducedBarrelRecHitProducer_;
      edm::InputTag reducedEndcapRecHitProducer_;

      edm::InputTag reducedBarrelRecHitToken_;
      edm::InputTag reducedEndcapRecHitToken_; 

      edm::InputTag reducedEgammaCollection_;
      edm::InputTag rhoIsoInputTag_;
      edm::InputTag tok_EB_;
      edm::InputTag tok_EE_;
      edm::InputTag electronToken_;
      edm::InputTag jetToken_;
      edm::InputTag pfToken_;
      edm::InputTag muonToken_;
      edm::InputTag prunedGenToken_;
      edm::InputTag packedGenToken_;
      edm::InputTag  triggerBits_;
      edm::InputTag  triggerObjects_;
      edm::InputTag  triggerPrescales_;

      //===============================
      // root file to store histograms
      TFile*  rootFile_;
      // min and max of energy histograms
      
      
      

};


#endif



