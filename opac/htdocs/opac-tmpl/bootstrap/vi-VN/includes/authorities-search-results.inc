[% BLOCK showreference %]
[%# Parameters: %]
[%# heading: the heading itself %]
[%# linkType: currently 'seefrom' or 'seealso', controls the label for the entry %]
[%# type: %]
[%# authid: if it is a linked authority, its authid %]

 [% SET authidurl = '/cgi-bin/koha/opac-authoritiesdetail.pl?authid=' %]
 [% SET searchurl = '/cgi-bin/koha/opac-authorities-home.pl?op=do_search&type=opac&operator=contains&marclist=mainentry&and_or=and&orderby=HeadingAsc&value=' %]
 [% IF marcflavour == 'UNIMARC' %]
 [% SWITCH type %]
 [% CASE 'broader' %]
 <span class="BT"><abbr title="Broader Term">BT</abbr>: [% heading | html %]</span>
 [% CASE 'narrower' %]
 <span class="NT"><abbr title="Narrower Term">NT</abbr>: [% heading | html %]</span>
 [% CASE 'seefrom' %]
 <span class="UF"><abbr title="Used For">UF</abbr>: [% heading | html %]</span>
 [% CASE 'seealso' %]
 <span class="RT"><abbr title="Related Term">RT</abbr>: [% heading | html %]</span>
 [% END %]
 [% ELSE %]
 <span class="heading">
 [% IF ( linkType=='seealso' ) %]
 [% IF ( authid ) %]
 <a href="[% authidurl | url %][% authid | uri %]">[% heading | html %]</a>
 [% ELSE %]
 <a href="[% searchurl | url %][% heading | uri %]">[% heading | html %]</a>
 [% END %]
 [% ELSE %]
 [% heading | html %]
 [% END %]
 </span>
 [% UNLESS ( type=='seefrom' || type=='seealso' ) %]
 <span class="type">
 [% SWITCH type %]
 [% CASE 'earlier' %]<span>(Earlier heading)</span>
 [% CASE 'later' %]<span>(Later heading)</span>
 [% CASE 'acronym' %]<span>(Acronym)</span>
 [% CASE 'musical' %]<span>(Musical composition)</span>
 [% CASE 'broader' %]<span>(Broader heading)</span>
 [% CASE 'narrower' %]<span>(Narrower heading)</span>
 [% CASE 'parent' %]<span>(Immediate parent body)</span>
 [% CASE %]
 [% IF type %]([% type | html %])[% END %]
 [% END %]
 </span>
 [% END # / UNLESS seefrom %]
 [% END # / IF marcflavour = 'UNIMARC' %]
[% END # / BLOCK showreference %]

[% BLOCK authresult %]
 [% IF ( summary.label ) %][% summary.label | html %]:[% END %]
 [% IF summary.summary %]
 <div class="authority-summary">
 [% summary.summary | html %]
 </div>
 [% END %]
 [% UNLESS ( summary.summaryonly ) %]
 <div class="authorizedheading">
 [% FOREACH authorize IN summary.authorized %]
 <span class="authorizedheading">[% authorize.heading | html %]</span>
 [% UNLESS loop.last %] | [% END %]
 [% END %]
 </div>
 [% IF ( marcflavour == 'UNIMARC' ) %]
 [% IF summary.notes %]
 <div class="authres_notes">
 [% FOREACH note IN summary.notes %]
 <span>[% note.note | html %]</span>
 [% END %]
 </div>
 [% END %]
 [% IF summary.seealso %]
 <div class="authres_seealso">
 [% FOREACH see IN summary.seealso %]
 [% PROCESS showreference heading=see.heading linkType="" type=see.type search='' %]
 [% IF ! loop.last %] ; [% END %]
 [% END %]
 </div>
 [% END %]
 [% IF summary.otherscript %]
 <div class="authres_otherscript">
 [% FOREACH other IN summary.otherscript %]
 [% PROCESS language lang=other.lang | trim %]:
 [% other.term | html %]
 [% IF ! loop.last %] ; [% END %]
 [% END %]
 </div>
 [% END %]
 [% ELSE %]
 [% IF ( summary.seefrom.size >= 1 ) %]
 <span class="seefrom">Sử dụng cho/Xem thêm từ:</span>
 [% FOREACH seefro IN summary.seefrom %]
 <div class="seefrom authref">
 [%# Following on one line for translatability %]
 [% PROCESS showreference heading=seefro.heading linkType='seefrom' type=seefro.type %]
 </div>
 [% END %]
 [% END %]
 [% IF ( summary.seealso.size >= 1 ) %]
 <span class="seealso">xem thêm:</span>
 [% FOREACH seeals IN summary.seealso %]
 <div class="seealso authref">
 [%# Following on one line for translatability %]
 [% PROCESS showreference heading=seeals.heading linkType='seealso' type=seeals.type authid=seeals.authid %]
 </div>
 [% END %]
 [% END %]
 [% END # / IF marcflavour = 'UNIMARC' %]
 [% END # / UNLESS summary.summaryonly %]
[% END # / BLOCK authresult %]
