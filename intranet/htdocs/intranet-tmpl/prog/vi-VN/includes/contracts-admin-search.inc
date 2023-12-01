[% USE Koha %]
<!-- contracts-admin-search.inc -->
<div id="header_search" role="tablist">
 <div class="tab-content">
 <div id="contract_description_search" role="tabpanel" class="tab-pane active">
 <form action="[% script_name | html %]" method="post">
 <div class="form-title">
 <label class="control-label">Tìm hợp đồng</label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" id="searchfield" name="searchfield" placeholder="Tìm kiếm theo tên hợp đồng hoặc nội dung:" size="40" type="text" value="[% searchfield | html %]" />
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 </div>

 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% INCLUDE 'patron-search-box.inc' %]
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 [% INCLUDE 'catalogue-search-box.inc' %]
 [% END %]

 </div><!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 <li role="presentation" class="active">
 <a aria-controls="contract_description_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#contract_description_search" role="tab" title="Tìm hợp đồng"><i class="fa fa-pencil-square-o"></i> <span class="tab-title">Tìm hợp đồng</span></a>
 </li>
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li role="presentation">
 <a aria-controls="circ_search" class="keep_text" data-toggle="tab" href="#circ_search" role="tab" title="Ghi mượn"><i class="fa fa-upload"></i> <span class="tab-title">Ghi mượn</span></a>
 </li>
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 <li role="presentation">
 <a title="Search catalog" href="#catalog_search" aria-controls="catalog_search" role="tab" data-toggle="tab" class="keep_text"><i class="fa fa-fw fa-search"></i> <span class="tab-title">Tìm kiếm danh mục</span></a>
 </li>
 [% END %]
 </ul>
</div><!-- /#header_search -->
<!-- contracts-admin-search.inc -->
